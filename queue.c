/*
	Queue.c implements a queue module.
*/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Pushes an element to queue
void push_queue(Queue ** q, Raw * r) {
	Queue * new_q = (Queue *) malloc(sizeof(Queue));
	Queue * curr = *q;
	if(new_q == NULL) { // Handles allocation issue
		printf("Cannot push to queue.\n");
		return;
	}
	new_q->next = NULL; // The new element will be pushed at the end
	if(curr == NULL) { // If queue is empty - In case of a new Queue.
		new_q->data = r;
		*q = new_q;
	} else {
		while(curr != NULL) {
			if(curr->next == NULL) { // If it has hit the current tail
				new_q->data = r;
			curr->next = new_q; // Add the new element to queue
				return;
			}
				curr = curr->next;
		}
	}
}

// Pops queue head and pushes to stack (used as a memory)
void pop_queue(Queue ** q, Stack ** s) {
	if(*q == NULL) { // Cannot pop an empty queue
		printf("Queue already empty.\n");
		return;
	}
	Queue * tmp = *q;
	push_stack(s, tmp->data); // Adds the popped data to the stack to memorize
	*q = (*q)->next; // Pop queue head
	free(tmp); // Free space allocated for previous head
}

// Prints queue elements
void print_queue(Queue ** q) {
	Queue * curr = *q;
	while(curr != NULL) { // Print until hitting the tail
		print_raw(curr->data);
		curr = curr->next;
	}
	printf("\n");
}