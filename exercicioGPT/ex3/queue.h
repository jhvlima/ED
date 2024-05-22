// queue.h
#ifndef QUEUE_H
#define QUEUE_H

typedef struct _Queue Queue;
typedef struct _Job Job;

/**
 * @brief Initializes a new queue.
 *
 * @return A pointer to the newly created queue.
 */
Queue *createQueue();

/**
 * @brief Adds a new job to the queue.
 *
 * @param queue A pointer to the queue structure.
 * @param jobId The ID of the job.
 * @param description The description of the job.
 */
void enqueue(Queue *queue, int jobId, const char *description);

/**
 * @brief Removes and returns the job at the front of the queue.
 *
 * @param queue A pointer to the queue structure.
 * @return A pointer to the job at the front of the queue. Returns NULL if the queue is empty.
 */
Job *dequeue(Queue *queue);

/**
 * @brief Checks if the queue is empty.
 *
 * @param queue A pointer to the queue structure.
 * @return 1 if the queue is empty, 0 otherwise.
 */
int isQueueEmpty(Queue *queue);

/**
 * @brief Frees all resources used by the queue.
 *
 * @param queue A pointer to the queue structure.
 */
void destroyQueue(Queue *queue);

/**
 * @brief Gets the job ID.
 * 
 * @param job A pointer to the job structure.
 * @return The job ID.
 */
int getJobId(Job *job);

/**
 * @brief Gets the job description.
 * 
 * @param job A pointer to the job structure.
 * @return The job description.
 */
const char* getJobDescription(Job *job);

void desalocaJob(Job *j);


#endif // QUEUE_H
