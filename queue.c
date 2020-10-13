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
    queue->last = 0;
    queue->size = size;
    queue->signal = 0;
    queue->array = (char**)malloc(sizeof(char*)*size);
    //sem_init(&queue->mutex,0,1);
    sem_init(&queue->enList,0,size);
    sem_init(&queue->deList,0,0);

    return queue;
}


/*
 * Enqueue with inStr to the last
 */
void EnqueueString(Queue* const q, char* const inStr){
    clock_t start, finish;
    start = clock();
    sem_wait(&q->enList);
    q->array[q->last] = inStr;
    countEnqueue(&(q->stat));
    q->last = (q->last+1)%(q->size);
    sem_post(&q->deList);
    //sem_post(&q->mutex);
    finish = clock();
    enqueueTimer(&(q->stat), finish - start);

}

/*
 * dequeue the first in queue
 */
char* DequeueString(Queue* const q){
    // check finished signal
    if(q->signal && q->first == q->last)
        return NULL;
    clock_t start, finish;
    start = clock();
    sem_wait(&q->deList);
    char* ret = q->array[q->first];
    q->array[q->first] = NULL;
    q->first = (q->first+1)%(q->size);
    countDequeue(&(q->stat));
    sem_post(&q->enList);
    finish = clock();
    dequeueTimer(&(q->stat), finish - start);
    return ret;

}


/*
 * output function
 */
void PrintQueueStats(Queue* const q){
    printStats(q->stat);

}