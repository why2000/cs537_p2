//
// Created by Hanyuan Wu on 10/7/20.
// team members: Hanyuan Wu, Zhihao Shu

#include "munch2.h"

/*
 * Thread: Munch2
 * Function: Get strings from Munch1 and send them to the Writer (using queues)
 * Params: QueueIO* qIO, a simple struct which is the pack of two queues (named inQ and outQ)
 */
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

/*
 * The function acting on inStr, replacing all lower chars into upper form.
 */
void strtoup(char* const inStr){
    for(unsigned long i = 0; inStr[i] != '\0' && i < MAX_LINE; i++){
        if(islower(inStr[i]))
            inStr[i] = (char)toupper(inStr[i]);
    }
}