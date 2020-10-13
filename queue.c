//
// Created by Zhihao Shu on 10/4/20.
// team members: Hanyuan Wu, Zhihao Shu

#include "queue.h"

/*
 * Init queue
 */
Queue* CreateStringQueue(int size){
    Queue *queue = malloc(sizeof(Queue));
    queue->first = 0;
    queue->items = 0;
    queue->size = size;
    queue->signal = 0;
    queue->array = (char**)malloc(sizeof(char*)*size);
    queue->stat.enqueueTime = 0;
    queue->stat.dequeueTime = 0;
    pthread_mutex_init(&queue->mutex, NULL);
    return queue;
}


/*
 * Enqueue with inStr to the last
 */
void EnqueueString(Queue* const q, char* const inStr){
    struct timeval start, finish, itvl;
    gettimeofday(&start, NULL);
    pthread_mutex_lock(&q->mutex);
    while(q->items == q->size)
        pthread_cond_wait(&q->nonFull, &q->mutex);
    q->array[(q->first+q->items)%q->size] = inStr;
    countEnqueue(&q->stat);
    q->items++;
    pthread_cond_signal(&q->nonEmpty);
    pthread_mutex_unlock(&q->mutex);
    gettimeofday(&finish, NULL);
    timersub(&finish, &start, &itvl);
    enqueueTimer(&q->stat, itvl.tv_sec+(1.0*itvl.tv_usec)/1e6);

}

/*
 * dequeue the first in queue
 */
char* DequeueString(Queue* const q){
    // check finished signal
    if(q->signal && q->items == 0){
        return NULL;
    }
    struct timeval start, finish, itvl;
    gettimeofday(&start, NULL);
    pthread_mutex_lock(&q->mutex);
    while(q->items == 0)
        pthread_cond_wait(&q->nonEmpty, &q->mutex);
    char* ret = q->array[q->first];
    q->array[q->first] = NULL;
    q->first = (q->first+1)%(q->size);
    q->items--;
    countDequeue(&q->stat);
    pthread_cond_signal(&q->nonFull);
    pthread_mutex_unlock(&q->mutex);
    gettimeofday(&finish, NULL);
    timersub(&finish, &start, &itvl);
    dequeueTimer(&q->stat, itvl.tv_sec+(1.0*itvl.tv_usec)/1e6);
    return ret;

}


/*
 * output function
 */
void PrintQueueStats(Queue* const q){
    printStats(q->stat);
}