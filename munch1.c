//
// Created by Hanyuan Wu on 10/7/20.
// team members: Hanyuan Wu, Zhihao Shu

#include "munch1.h"

/*
 * Thread: Munch1
 * Function: Get strings from the Reader and send them to munch2 (using queues)
 * Params: QueueIO* qIO, a simple struct which is the pack of two queues (named inQ and outQ)
 */
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

/*
 * The function acting on inStr, replacing all chars equal to 'src' into 'tgt'
 */
void strrpl(char* const inStr, const char src, const char tgt){
    for(unsigned long i = 0; inStr[i] != '\0' && i < MAX_LINE; i++){
        if(inStr[i] == src)
            inStr[i] = tgt;
    }
}