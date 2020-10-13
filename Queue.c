//
// Created by Zhihao Shu on 10/4/20.
// team members: Hanyuan Wu, Zhihao Shu

#include "Queue.h"

#include "Queue.h"


sem_t mutex;
sem_t list;


Queue *CreateStringQueue(int size){
    Queue *queue = malloc(sizeof(Queue));
    queue->first = 0;
    queue->last = 0;
    queue->size = size;
    queue->array = (char**)malloc(sizeof(char*)*size);
    sem_init(&mutex,0,1);
    sem_init(&list,0,0);

    return queue;
}


void EnqueueString(Queue *q, char* string){
    clock_t start, finish;
    start = clock();
    sem_wait(&mutex);
    while((q->last+1)%(q->size) == q->first){
        sem_wait(&list);
    }
    q->array[q->last] = string;
    //increment count
    q->enqueueCount++;
    q->last = (q->last+1)%(q->size);
    sem_post(&list);
    sem_post(&mutex);
    finish = clock();
    q->enqueueTime = (double)(finish - start);

}

char* DequeueString(Queue *q){
    clock_t start, finish;
    start = clock();
    sem_wait(&mutex);
    while(q->first == q->last){
        sem_wait(&list);
    }
    char* ret = q->array[q->first];
    q->first = (q->first+1)%(q->size);
    q->dequeueCount++;
    sem_post(&list);
    sem_post(&mutex);
    finish = clock();
    q->dequeueTime = (double)(finish - start);
    return ret;
}

void PrintQueueStats(Queue *q){
    sem_wait(&mutex);

    sem_post(&mutex);

}