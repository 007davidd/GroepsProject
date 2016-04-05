//
// Created by david on 3/13/2016.
//

#ifndef PRACTICUM_OPDRACHT_5_5_QUEUE_H
#define PRACTICUM_OPDRACHT_5_5_QUEUE_H


#define QUEUESIZE 50
typedef struct {
    int a[QUEUESIZE];
    int head;
    int tail;
} Queue;


void init_queue(Queue *pq);

void enqueue(Queue *pq, int data);

int dequeue(Queue *pq);


#endif //PRACTICUM_OPDRACHT_5_5_QUEUE_H
