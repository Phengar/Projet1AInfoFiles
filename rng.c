#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/random.h>

//#define RAND_MAX 32767   //RAND_MAX has base value of 2147483647


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

float random_gen(){
	float tmp =  (float) rand();
	return  tmp/2147483647;
}



void main(){
	getseed();
	for(int i=0; i<50; i++){
		printf("%f\n", random_gen());
	}
	//printf("unsigned int with good value: %c\n", t);
}