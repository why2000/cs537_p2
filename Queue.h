//
// Created by Zhihao Shu on 10/4/20.
// team members: Hanyuan Wu, Zhihao Shu


#ifndef PRODCOM_QUEUE_H
#define PRODCOM_QUEUE_H

#define TEST_SIZE 10
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/time.h>
#include <time.h>


typedef struct{
    char** array;
    int first;
    int last;
    int size;
    int enqueueCount;
    int dequeueCount;
    double enqueueTime;
    double dequeueTime;
} Queue;

Queue *CreateStringQueue(int size);

void EnqueueString(Queue *q, char *string);

char * DequeueString(Queue *q);

void PrintQueueStats(Queue *q);

#endif //PRODCOM_QUEUE_H
