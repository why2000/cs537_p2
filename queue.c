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
    if(sem_init(&queue->mutex,0, 1) != 0){
        perror("failed to init sem mutex");
    }
    if(sem_init(&queue->enList,0,size) != 0){
        perror("failed to init sem enList");
    }
    if(sem_init(&queue->deList,0,0)){
        perror("failed to init sem deList");
    }
    return queue;
}


/*
 * Enqueue with inStr to the last
 */
void EnqueueString(Queue* const q, char* const inStr){
    clock_t start, finish;
    start = clock();
    sem_wait(&q->enList);
    sem_wait(&q->mutex);
    q->array[(q->first+q->items)%q->size] = inStr;
    countEnqueue(&q->stat);
    q->items++;
    finish = clock();
    enqueueTimer(&q->stat, finish - start);
    sem_post(&q->deList);
    sem_post(&q->mutex);


}

/*
 * dequeue the first in queue
 */
char* DequeueString(Queue* const q){
    // check finished signal
    if(q->signal && q->items == 0){
        return NULL;
    }
    clock_t start, finish;
    start = clock();
    sem_wait(&q->deList);
    sem_wait(&q->mutex);
    char* ret = q->array[q->first];
    q->array[q->first] = NULL;
    q->first = (q->first+1)%(q->size);
    q->items--;
    countDequeue(&q->stat);
    finish = clock();
    dequeueTimer(&q->stat, finish - start);
    sem_post(&q->enList);
    sem_post(&q->mutex);
    return ret;

}


/*
 * output function
 */
void PrintQueueStats(Queue* const q){
    sem_wait(&q->mutex);
    printStats(q->stat);
    sem_post(&q->mutex);
}