//
// Created by Hanyuan Wu on 10/7/20.
// team members: Hanyuan Wu, Zhihao Shu

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
    unsigned long length = strlen(inStr);
    for(unsigned long i = 0; i < length+1; i++){
        if(inStr[i] == src)
            inStr[i] = tgt;
    }
}