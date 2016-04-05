#include "queue.h"

void init_queue(Queue *pq) {
	/*pq = NULL;
	pq = malloc(sizeof(Queue));*/

	for (int i = 0; i < QUEUESIZE; ++i) {
		pq->a[i] = 0;
	}
	pq->head = 0;
	pq->tail = 0;

}

void enqueue(Queue *pq, int data) {

	pq->tail++;
	pq->a[pq->tail] = data;

}

int dequeue(Queue *pq) {
	int r = pq->a[pq->head];
	pq->a[pq->head] = 0;
	pq->head++;
	return r;
}
