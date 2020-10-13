//
// Created by Hanyuan Wu on 10/7/20.
// team members: Hanyuan Wu, Zhihao Shu

#include "munch2.h"

void Munch2(void* qIO){
    Queue* inQ = ((QueueIO*)qIO)->inQ;
    Queue* outQ = ((QueueIO*)qIO)->outQ;
    char* bufStr;
    while((bufStr = DequeueString(inQ)) != NULL) {
        strtoup(bufStr);
        EnqueueString(outQ, bufStr);
        bufStr = NULL;
    }
    outQ->signal = 1;
    pthread_exit(0);

}

void strtoup(char* const inStr){
    unsigned long length = strlen(inStr);
    for(unsigned long i = 0; i < length+1; i++){
        if(islower(inStr[i]))
            inStr[i] = (char)toupper(inStr[i]);
    }
}