//
// Created by Zhihao Shu on 10/4/20.
// team members: Hanyuan Wu, Zhihao Shu

#include "queue.h"


Queue* CreateStringQueue(int size){
    Queue *queue = malloc(sizeof(Queue));
    queue->first = 0;
    queue->last = 0;
    queue->size = size;
    queue->signal = 0;
    queue->array = (char**)malloc(sizeof(char*)*size);
    sem_init(&queue->mutex,0,1);
    sem_init(&queue->enList,0,size);
    sem_init(&queue->deList,0,0);

    return queue;
}


void EnqueueString(Queue* const q, char* const string){
    clock_t start, finish;
    start = clock();
    // if the mutex sem is redundent?
    sem_wait(&q->enList);
    sem_wait(&q->mutex);
    q->array[q->last] = string;
    q->enqueueCount++;
    q->last = (q->last+1)%(q->size);
    sem_post(&q->deList);
    sem_post(&q->mutex);
    finish = clock();
    q->enqueueTime = (double)(finish - start);

}

char* DequeueString(Queue* const q){
    clock_t start, finish;
    start = clock();
    // check finished signal
    if(q->signal && q->first == q->last)
        return NULL;
    sem_wait(&q->deList);
    sem_wait(&q->mutex);
    char* ret = q->array[q->first];
    q->array[q->first] = NULL;
    q->first = (q->first+1)%(q->size);
    q->dequeueCount++;
    sem_post(&q->enList);
    sem_post(&q->mutex);
    finish = clock();
    q->dequeueTime = (double)(finish - start);
    return ret;

}

void PrintQueueStats(Queue* const q){
    sem_wait(&q->mutex);
    printf("enqueueCnt\tdequeueCnt\tenqueueTime\tdequeueTime\t");
    printf("%d\t%d\t%lf\t%lf",
           q->enqueueCount, q->dequeueCount, q->enqueueTime, q->dequeueTime);
    sem_post(&q->mutex);

}