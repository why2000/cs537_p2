//
// Created by hanyuan on 10/12/20.
//

#include "reader.h"

void Reader(void* vQ){
    Queue* q = (Queue*)vQ;
    char* bufStr;
    bufStr = (char*)malloc(sizeof(char)*MAX_LINE);
    while(fgets(bufStr, MAX_LINE, stdin) != NULL){
        EnqueueString(q, bufStr);
        bufStr = NULL;
        // register a new str
        bufStr = (char*)malloc(sizeof(char)*MAX_LINE);
    }
    q->signal = 1;
    pthread_exit(0);

}

