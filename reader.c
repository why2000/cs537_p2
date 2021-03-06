//
// Created by Hanyuan Wu on 10/7/20.
// team members: Hanyuan Wu, Zhihao Shu

#include "reader.h"

/*
 * Thread: Reader
 * Function: read string from stdin (or a certain file if DEBUG is defined)
 * Params: Queue* vQ, the queue to be sent the data read from stdin
 */
void Reader(void* vQ){
    Queue* q = (Queue*)vQ;
    char* bufStr;
    if((bufStr = (char*)malloc(sizeof(char)*MAX_LINE)) == NULL){
        perror("unable to alloc memory");
        pthread_exit(0);
    }

    while(fgets(bufStr, MAX_LINE, stdin) != NULL){
        EnqueueString(q, bufStr);
        bufStr = NULL;
        // register a new str
        if((bufStr = (char*)malloc(sizeof(char)*MAX_LINE)) == NULL){
            perror("unable to alloc memory");
            pthread_exit(0);
        }
    }
    q->signal = 1;
    pthread_exit(0);

}

