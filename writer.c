//
// Created by Hanyuan Wu on 10/7/20.
// team members: Hanyuan Wu, Zhihao Shu
// netID: hwu394 zshu9
// login: hanyuan hshu

#include "writer.h"

/*
 * Thread: Writer
 * Function: read string from munch2 (using queue) and print them to stdout
 * Params: Queue* vQ, the queue to be sent the data read from stdin
 */
void Writer(void* vQ){
    Queue* q = (Queue*)vQ;
    char* bufStr;
    while((bufStr = DequeueString(q)) != NULL) {
        printf("%s", bufStr);
        free(bufStr);
        bufStr = NULL;
    }
    printf("Number of lines processed: %d\n", getDequeueCount(q->stat));
    pthread_exit(0);

}
