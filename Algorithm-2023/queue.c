#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "tree.h"

static void error(char str[])
{
	printf("%s\n", str);
	exit(1);
}

void init_queue(Queue* q) { q->front = q->rear = 0; }
int is_empty(Queue* q) { return q->front == q->rear; }
int is_full(Queue* q) { return q->front == (q->rear + 1) % MAX_QUEUE_SIZE; }
int queue_size(Queue* q) { return (q->rear - q->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; }

void enqueue(Element val, Queue* q)
{
	if (is_full(q))
		error("큐 포화 에러");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = val;
}

Element dequeue(Queue* q)
{
	if (is_empty(q))
		error("큐 공백 에러");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

Element peek(Queue* q)
{
	if (is_empty(q))
		error("큐 공백 에러");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}