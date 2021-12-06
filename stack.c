/*
	Stack.c - implements a stack module.
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


// Pushes element to stack
void push_stack(Stack ** s, Raw * r) {
	Stack * new_s = (Stack *) malloc(sizeof(Stack));
	if(new_s == NULL) { // Handles allocation issue
		printf("Cannot push to stack.\n");
		return;
	}
	new_s->data = r;
	new_s->next = *s;
	*s = new_s; // The new element is now on stack head
}

// Pops stack head
void pop_stack(Stack ** s) {
	if(*s == NULL) { // Cannot pop an already empty stack
		printf("Stack already empty.\n");
		return;
	}
	Stack * tmp = *s;
	*s = (*s)->next; // Pops stack head
	free(tmp); // Free space allocated for previous head
}

// Frees the entire stack from memory
void free_stack(Stack ** s) {
	while(*s != NULL) {
		pop_stack(s);
	}
}

// Returns stack size
int size_stack(Stack ** s) {
	Stack * curr = *s;
	int size = 0;
	while(curr != NULL) {
		size++;
		curr = curr->next;
	}
	return size;
}

// Prints stack elements
void print_stack(Stack ** s) {
	Stack * curr = *s;
	while(curr != NULL) {
		print_raw(curr->data);
		curr = curr->next;
	}
	printf("\n");
}