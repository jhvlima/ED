#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

typedef struct _celula tCelula;
struct _celula
 {
    Job* dado;
    tCelula *proxima;
 };
 
struct _Queue
{
    tCelula *ultima;
    tCelula *primeira; 
};

struct _Job
{
    int id;
    char *description;
};

/**
 * @brief Initializes a new queue.
 *
 * @return A pointer to the newly created queue.
 */
Queue *createQueue()
{
    Queue *fila = calloc(1, sizeof(tCelula));
    return fila;
}

/**
 * @brief Adds a new job to the queue.
 *
 * @param queue A pointer to the queue structure.
 * @param jobId The ID of the job.
 * @param description The description of the job.
 */
void enqueue(Queue *queue, int jobId, const char *description)
{
    tCelula *nova = calloc(1, sizeof(tCelula));
    Job *job = malloc(sizeof(Job));
    job->description = strdup(description);
    job->id = jobId;
    nova->dado = job;
    nova->proxima = NULL;

    // caso fila vazia
    if (isQueueEmpty(queue))
    {
        queue->primeira = queue->ultima = nova;
    }

    // insere no final
    else
    {
        queue->ultima->proxima = nova;
        queue->ultima = nova;
    }
}

/**
 * @brief Removes and returns the job at the front of the queue.
 *
 * @param queue A pointer to the queue structure.
 * @return A pointer to the job at the front of the queue. Returns NULL if the queue is empty.
 */
Job *dequeue(Queue *queue)
{
    if (!isQueueEmpty(queue))
    {
        tCelula *cel = queue->primeira;
        Job *job = cel->dado;
        queue->primeira = queue->primeira->proxima;
        free(cel);
        return job;
    }
}

/**
 * @brief Checks if the queue is empty.
 *
 * @param queue A pointer to the queue structure.
 * @return 1 if the queue is empty, 0 otherwise.
 */
int isQueueEmpty(Queue *queue)
{
    if (queue->primeira)
    {
        return 0;
    }
    return 1;
}

void desalocaJob(Job *j)
{
    free(j->description);
    free(j);
}

/**
 * @brief Frees all resources used by the queue.
 *
 * @param queue A pointer to the queue structure.
 */
void destroyQueue(Queue *queue)
{
    while (!isQueueEmpty(queue))
    {
        desalocaJob(dequeue(queue));
    }
    free(queue);
}

/**
 * @brief Gets the job ID.
 * 
 * @param job A pointer to the job structure.
 * @return The job ID.
 */
int getJobId(Job *job)
{
    return job->id;
}

/**
 * @brief Gets the job description.
 * 
 * @param job A pointer to the job structure.
 * @return The job description.
 */
const char* getJobDescription(Job *job)
{
    return job->description;
}
