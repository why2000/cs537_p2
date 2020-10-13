//
// Created by Zhihao Shu on 10/4/20.
// team members: Hanyuan Wu, Zhihao Shu


#ifndef PRODCOM_QUEUE_H
#define PRODCOM_QUEUE_H
#include "prodcom.h"
#include "statistic.h"

typedef struct{
    int signal;
    int first;
    int items;
    int size;
    char** array;
    sem_t enList;
    sem_t deList;
    sem_t mutex;
    Stat stat;
} Queue;


typedef struct{
    Queue* inQ;
    Queue* outQ;
} QueueIO;

Queue* CreateStringQueue(int size);

void EnqueueString(Queue *q, char *string);

char* DequeueString(Queue *q);

void PrintQueueStats(Queue *q);

#endif //PRODCOM_QUEUE_H
