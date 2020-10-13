//
// Created by Hanyuan Wu on 10/7/20.
// team members: Hanyuan Wu, Zhihao Shu

#include "writer.h"

void Writer(void* vQ){
    Queue* q = (Queue*)vQ;
    char* bufStr;
    while((bufStr = DequeueString(q)) != NULL) {
        printf("%s", bufStr);
        free(bufStr);
        bufStr = NULL;
    }
    q->signal = 1;
    printf("Number of lines processed: %d\n", getDequeueCount(q->stat));
    pthread_exit(0);

}