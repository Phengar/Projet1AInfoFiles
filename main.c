#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"
#include "save.h"
#include "data.h"




#define lambda 0.001
#define minsrv 40
#define maxsrv 300 

void getseed(){ 							// sets up rand() by getting a true random seed from seed_generator
	FILE *file;
	char t[100];
	//printf("unisgned int just created: %c\n", t);
	file= popen("./seed_generator", "r");   // runs seed_generator and gets a true random seed
	fgets(t, sizeof(t), file);
	int seed= atoi(t);                      // transforms the string seed to int seed
	//printf("%d", seed);
	pclose(file);
	srand(seed);							// sets up rand()
}

float random_unif(){
	float tmp =  (float) rand();
	return  tmp/RAND_MAX;
}

float random_expo(float lamb){
	return -logf(1-random_unif())/lamb;
}

float random_srvtime(){
	return random_unif()*(maxsrv-minsrv)+minsrv;
}

/*int sup(float a, float b, * value){
	if (a>b){
		DO SOMETHING WITH VALUE
		return 1;
	}
	DO SOMETHING ELSE WITH VALUE
	return 0;
} WIP*/




int main(int argc, char * argv[]) {
	if (argc != 2){
		printf("use 'number of days' to run the simulation");
		return 0;
	}
	getseed();
	
	int day = 1;
	int time =0;




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