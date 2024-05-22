// main.c
#include <stdio.h>
#include "queue.h"

int main()
{
    Queue *printQueue = createQueue();

    // Add jobs to the print queue
    enqueue(printQueue, 1, "Print document A");
    enqueue(printQueue, 2, "Print document B");
    enqueue(printQueue, 3, "Print document C");

    // Process jobs in the print queue
    while (!isQueueEmpty(printQueue))
    {
        Job *job = dequeue(printQueue);
        printf("Processing job %d: %s\n", getJobId(job), getJobDescription(job));
        desalocaJob(job);
    }

    destroyQueue(printQueue);
    return 0;
}
