#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"
#include "save.h"
#include "data.h"

int main() {
	char * raw_file = "raw.txt", * processed_file = "processed.txt";
	
	Queue * q = NULL;
	Stack * s = NULL;
	Raw r1 = {1, 2, 3, 4, 5}, r2 = {6, 7, 8, 9, 10};
	Processed p = {11, 12, 13, 14, 15};

	print_raw(&r1);
	print_processed(&p);

	printf("\n");

	printf("Pushing two elements to queue :\n");
	push_queue(&q, &r1);
	push_queue(&q, &r2);
	print_queue(&q);

	printf("\n");

	pop_queue(&q, &s);
	printf("Queue after one pop :\n");
	print_queue(&q);
	printf("Stack after one queue pop :\n");
	print_stack(&s);
	pop_queue(&q, &s);
	printf("Queue after two pop :\n");
	print_queue(&q);
	printf("Stack after two queue pop :\n");
	print_stack(&s);

	printf("\n");

	printf(">> Saving raw data to : %s\n", raw_file);
	save_raw(raw_file, &s);
	printf(">> Saved... Hopefully !\n\n");
	printf(">> Saving processed data to : %s\n", processed_file);
	save_processed(processed_file, &p);
	printf(">> Saved... I hope so...\n");

	printf("\n");

	Stack * s2 = NULL;
	push_stack(&s2, &r1);
	push_stack(&s2, &r2);
	print_stack(&s2);
	printf("\n %d \n", size_stack(&s2));
	pop_stack(&s2);
	pop_stack(&s2);
	printf("\n\n");
	printf("Trying to load raw data from file.\n");
	load_raw(raw_file, &s2);
	printf("\n %d \n", size_stack(&s2));
	printf("Result :\n");
	print_stack(&s2);
}