//
// Created by Laurence St-Germain on 2018-10-11.
//

#ifndef CS201_DEV3_PQUEUE_LSTGERMA_H
#define CS201_DEV3_PQUEUE_LSTGERMA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[16];
} DataNode;

typedef struct PQN {
    int priority;
    void *data;
    struct PQN *next;
} PQueueNode;

typedef struct {
    PQueueNode *head;
    PQueueNode *tail;
} PQueue;


int enqueue (PQueue *pqueue, int priority, void *data);
/* put node in queue in priority order; in case of tie in priority,
 * then put node after all nodes with the specified priority;
 * this function should always return 0*/

void *dequeue (PQueue *pqueue);
/* return NULL if queue is empty; otherwise return the dat (the DataNode)
 * from the first node in the queue (since the queue is maintained in
 * priority order--from lowest to highest-- this will be the data from the
 * node having the smallest prority value) */

int printQueue (PQueue *pqueue);
/* print queue from head to tail; this function should always return 0 */

void *peek (PQueue *pqueue);
/* return the first node in the queue, but do not remove it;
 * return NULL if queue is empty */

int getMinPriority (PQueue *pqueue);
/* return priority of first node in queue;
 * return -1 if queue is empty */

#endif //CS201_DEV3_PQUEUE_LSTGERMA_H
