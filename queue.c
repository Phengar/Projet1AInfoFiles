/*
	Queue.c implements a queue module.
*/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Queue Structure
struct node {
	struct node * next;
	int id;
};


// Push an element to queue
void push(Queue ** q) { // NEEDED //Add offset
	Queue * new_q = (Queue *) malloc(sizeof(Queue));
	Queue * curr = *q;
	if(new_q == NULL) { // Handles allocation issue
		printf("Cannot push.\n");
		return;
	}
	new_q->next = NULL; // The new element will be pushed at the end
	if(curr == NULL) { // if Queue is empty - New Queue
		new_q->id = 0;
		*q = new_q;
	} else { // Instead if Queue is not empty
		while(curr != NULL) {
			if(curr->next == NULL) { // If it has hit the current tail
				new_q->id = curr->id+1;
				curr->next = new_q; // Add the new element to queue
				return;
			}
			curr = curr->next;
		}
	}
}

// Pop queue head
void pop(Queue ** q) {
	if(*q == NULL) { // Cannot pop an empty queue
		printf("Queue already empty.\n");
		return;
	}
	*q = (*q)->next; // Pop queue head
}

// Print queue elements
void print(Queue ** q) {
	Queue * curr = *q;
	while(curr != NULL) { // Print until hitting the tail
		printf("%d ", curr->id);
		curr = curr->next;
	}
	printf("\n");
}

/*
int main() {
	Queue * q = NULL;
	push(&q);
	push(&q);
	push(&q);
	push(&q);
	push(&q);
	push(&q);
	print(&q);
	pop(&q);
	print(&q);
	pop(&q);
	print(&q);
	pop(&q);
	print(&q);
	pop(&q);
	print(&q);
	pop(&q);
	print(&q);
	pop(&q);
	print(&q);
	pop(&q);
	print(&q);
	return 0;
}*/
