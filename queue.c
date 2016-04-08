#include "queue.h"

void init_queue(Queue* pq)
{
	pq->head = 0;
	pq->tail = -1;
}

void enqueue(Queue* pq, int data)
{
	if (pq->tail < (QUEUESIZE -1))
	{
		(pq->tail)++;
		pq->a[pq->tail] = data;
	}
}

int dequeue(Queue* pq)
{
	int data = 0;
	if (pq->head <= pq->tail)
	{
		data = pq->a[pq->head];
		(pq->head)++;
	}
	return data;
}
