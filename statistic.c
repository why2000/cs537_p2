//
// Created by Hanyuan Wu on 10/7/20.
// team members: Hanyuan Wu, Zhihao Shu

#include "statistic.h"

void countEnqueue(Stat* const stat){
    stat->enqueueCount++;
}

int getEnqueueCount(const Stat stat){
    return stat.enqueueCount;
}

void countDequeue(Stat* const stat){
    stat->dequeueCount++;
}

int getDequeueCount(const Stat stat){
    return stat.dequeueCount;
}

void enqueueTimer(Stat* const stat, const double itvl){
    stat->enqueueTime += itvl;
}

double getEnqueueTime(const Stat stat){
    return stat.enqueueTime;
}

void dequeueTimer(Stat* const stat, const double itvl){
    stat->dequeueTime += itvl;
}

double getDequeueTime(const Stat stat){
    return stat.dequeueTime;
}

void printStats(const Stat stat){
    fprintf(stderr, "enqueueCnt\tdequeueCnt\tenqueueTime\tdequeueTime\n");
    fprintf(stderr, "%d\t%d\t%lf\t%lf\n",
           getEnqueueCount(stat),getDequeueCount(stat),getEnqueueTime(stat),getDequeueTime(stat));
}
