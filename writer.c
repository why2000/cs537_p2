//
// Created by hanyuan on 10/12/20.
//

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
    printf("Number of lines processed: %d\n", q->dequeueCount);
    pthread_exit(0);

}