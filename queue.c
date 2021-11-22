/*
	Queue.c implements a queue module.
*/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"

// Pushes an element to queue
/*
	offset serves in case the whole queue has
	been popped at least once. So that once we push
	new values into queue they don't start with id: 0
*/
void push(Queue ** q, int offset) {
	Queue * new_q = (Queue *) malloc(sizeof(Queue));
	Queue * curr = *q;
	if(new_q == NULL) { // Handles allocation issue
		printf("Cannot push.\n");
		return;
	}
	new_q->next = NULL; // The new element will be pushed at the end
	if(curr == NULL) { // if Queue is empty - in case of a new queue
		new_q->id = offset;
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

// Pop queue head and pushes to stack
void pop(Queue ** q, char * fname) {
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
	push(&q, 0);
	push(&q, 0);
	push(&q, 0);
	push(&q, 0);
	push(&q, 0);
	push(&q, 0);
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
