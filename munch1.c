//
// Created by hanyuan on 10/12/20.
//

#include "munch1.h"

void Munch1(void* qIO){
    Queue* inQ = ((QueueIO*)qIO)->inQ;
    Queue* outQ = ((QueueIO*)qIO)->outQ;
    char* bufStr;
    while((bufStr = DequeueString(inQ)) != NULL) {
        strrpl(bufStr, ' ', '*');
        EnqueueString(outQ, bufStr);
        bufStr = NULL;
    }
    outQ->signal = 1;
    pthread_exit(0);

}

void strrpl(char* const inStr, const char src, const char tgt){

}