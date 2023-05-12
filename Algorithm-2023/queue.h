#pragma once
#include "tree.h"
#define MAX_QUEUE_SIZE 100

typedef Node* Element;

typedef struct _queue {
	Element data[MAX_QUEUE_SIZE];
	int front;
	int rear;
}Queue;

void init_queue(Queue* q);
int is_empty(Queue* q);
int is_full(Queue* q);
int queue_size(Queue* q);
void enqueue(Element val, Queue* q);
Element dequeue(Queue* q);
Element peek(Queue* q);