//
// Created by Hanyuan Wu on 10/7/20.
// team members: Hanyuan Wu, Zhihao Shu

#ifndef PRODCOM_STATISTIC_H
#define PRODCOM_STATISTIC_H

#include "prodcom.h"

typedef struct{
    int enqueueCount;
    int dequeueCount;
    double enqueueTime;
    double dequeueTime;
} Stat;

void countEnqueue(Stat*);
int getEnqueueCount(Stat);
void countDequeue(Stat*);
int getDequeueCount(Stat);
void enqueueTimer(Stat*, clock_t);
double getEnqueueTime(Stat);
void dequeueTimer(Stat*, clock_t);
double getDequeueTime(Stat);
void printStats(Stat);

#endif //PRODCOM_STATISTIC_H
