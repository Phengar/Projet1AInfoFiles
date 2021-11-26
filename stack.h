#ifndef STACK_H_ // To avoid multiple including
#define STACK_H_

#include "data.h"

// Stack Structure
typedef struct stack_node {
	struct stack_node * next;
	Raw * data;
} Stack;

void push_stack(Stack ** s, Raw * r);

void pop_stack(Stack ** s);

int size_stack(Stack ** s);

void print_stack(Stack ** s);

#endif