//
// Created by Laurence St-Germain on 2018-10-11.
//

#include "pqueue.lstgerma.h"


int enqueue (PQueue *pqueue, int priority, void *data){
    PQueueNode *newNode = malloc(sizeof(PQueueNode));

    newNode->data = data;
    newNode->next=NULL;

    newNode->priority = priority;

    if(pqueue->head == NULL){
        pqueue->head = newNode;
        pqueue->tail = newNode;
    }
    else{
        pqueue->tail->next = newNode;
        pqueue->tail = newNode;

        PQueueNode *temp = pqueue->head;
        if (temp->priority > newNode->priority){
            pqueue->head = newNode;
            newNode->next = temp;
            return 0;
        }

        while (temp->next != NULL && temp->next->priority < newNode->priority){
            temp = temp->next;
        }

        if (temp->next != NULL){
            newNode->next = temp->next;
        }
        temp->next = newNode;
    }


}


void *dequeue (PQueue *pqueue){

    if(pqueue->head == NULL){
        return NULL;
    }
    else {
        PQueueNode *temp;
        temp = pqueue->head->data;
        pqueue->head = pqueue->head->next;

        free(temp);
        return temp;


    }
}




int printQueue (PQueue *pqueue){
    PQueue* current = pqueue;

    if(current == NULL){
        return 0;
    }
    else{
        while(current->head != NULL || current->tail==NULL){
            printf("%s %d ", current->head->data, current->head->priority );
            current->head = current->head->next;
            return 0;
        }
    }

    return 0;
}




void *peek (PQueue *pqueue){

    if(pqueue->head == NULL){
        return NULL;
    }
    else{
        return pqueue->head;
    }
}




int getMinPriority (PQueue *pqueue){
    if(pqueue->head == NULL){
        return -1;
    }
    else{
        return pqueue->head->priority;
    }
}