//
// Created by Hanyuan Wu on 10/7/20.
// team members: Hanyuan Wu, Zhihao Shu

#include "prodcom.h"

#include "queue.h"
#include "reader.h"
#include "munch1.h"
#include "munch2.h"
#include "writer.h"




int main(void) {
    Queue* queue1, * queue2, * queue3;
    queue1 = CreateStringQueue(TEST_SIZE);
    queue2 = CreateStringQueue(TEST_SIZE);
    queue3 = CreateStringQueue(TEST_SIZE);
    QueueIO pack1_2 = {.inQ=queue1,.outQ=queue2};
    QueueIO pack2_3 = {.inQ=queue2,.outQ=queue3};
    pthread_t reader, munch1, munch2, writer;

    if(pthread_create(&reader, NULL, (void*)Reader, queue1)!=0)
    {
        printf("Failed creating reader pthread\n");
        return -1;
    }
    if(pthread_create(&munch1, NULL, (void*)Munch1, &pack1_2)!=0)
    {
        printf("Failed creating munch1 pthread\n");
        return -1;
    }
    if(pthread_create(&munch2, NULL, (void*)Munch2, &pack2_3)!=0)
    {
        printf("Failed creating munch2 pthread\n");
        return -1;
    }
    if(pthread_create(&writer, NULL, (void*)Writer, queue3)!=0)
    {
        printf("Failed creating writer pthread\n");
        return -1;
    }
    pthread_join(reader, NULL);
    pthread_join(munch1, NULL);
    pthread_join(munch2, NULL);
    pthread_join(writer, NULL);

    fprintf(stderr,"Statics:\n");
    fprintf(stderr,"Queue between Reader and Munch1:\n");
    PrintQueueStats(queue1);
    fprintf(stderr,"Queue between Munch1 and Munch2:\n");
    PrintQueueStats(queue2);
    fprintf(stderr,"Queue between Munch2 and Writer:\n");
    PrintQueueStats(queue3);


    return 0;
}
