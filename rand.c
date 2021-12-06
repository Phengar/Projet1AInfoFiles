/*
	rand.c - Implements various random number generation related functions
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/random.h>
#include "rand.h"

// Sets a random seed
void setSeed() {
	unsigned int t;
    getrandom(&t, sizeof(unsigned int), GRND_NONBLOCK) ==-1 ? perror("Entropy pool not set up") : ""; //create crypto quality randomness // fill the adress of t with random bytes
    srand(t);
}

// Generates a random integer between minserv and maxserv - uniform law
int random_int(int minserv, int maxserv) {
	return minserv + (rand() % (maxserv - minserv + 1));
}

// Generates a random number accoring the uniform law
double random_unif() {
	return ((double) rand()) / RAND_MAX;
}

// Generates a random value according the exponential law with a lambda of lamb
double random_expo(double lamb) {
	return -logf(1 - random_unif()) / lamb;
}

/*
int main() {
	setSeed();
	double x;
	for(int i = 0; i < 100; i++) {
		x = random_expo(0.01);
		printf("%lf\n", x);
	}
	return 0;
}*/