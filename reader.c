//
// Created by Hanyuan Wu on 10/7/20.
// team members: Hanyuan Wu, Zhihao Shu

#include "reader.h"
//#define DEBUG
/*
 * Thread: Reader
 * Function: read string from stdin (or a certain file if DEBUG is defined)
 * Params: Queue* vQ, the queue to be sent the data read from stdin
 */
void Reader(void* vQ){
    Queue* q = (Queue*)vQ;
    char* bufStr;
    bufStr = (char*)malloc(sizeof(char)*MAX_LINE);
#ifdef DEBUG
    // for convinence
    FILE* fp = fopen("../test.txt", "r");
    while(fgets(bufStr, MAX_LINE, fp) != NULL){
#else
    while(fgets(bufStr, MAX_LINE, stdin) != NULL){
#endif
        EnqueueString(q, bufStr);
        bufStr = NULL;
        // register a new str
        bufStr = (char*)malloc(sizeof(char)*MAX_LINE);
    }
    q->signal = 1;
    pthread_exit(0);

}

