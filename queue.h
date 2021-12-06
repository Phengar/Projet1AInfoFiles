#ifndef QUEUE_H_ // To avoid multiple including
#define QUEUE_H_

#include "stack.h"

// Queue Structure
typedef struct queue_node {
	struct queue_node * next;
	Raw * data;
} Queue;

void push_queue(Queue ** q, Raw * r);

void pop_queue(Queue ** q, Stack ** s);

int size_queue(Queue ** q);

void free_queue(Queue ** q, Stack ** s);

void print_queue(Queue ** q);

#endif