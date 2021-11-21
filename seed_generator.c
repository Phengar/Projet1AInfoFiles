#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/random.h>

#define lambda 0.5

void main(){
	/*time_t t;
	srand(time(NULL));
	for(int i=0; i<20; i++){
		printf("%d\n", rand() %101);*/ //bad implementation of random
	/*int randomData =arc4random();
    printf("%d", randomData);/* problems with arc4random implementation*/
    unsigned int t;
    getrandom(&t, sizeof(unsigned int), GRND_NONBLOCK) ==-1 ? perror("Entropy pool not set up") : ""; //create crypto quality randomness // fill the adress of t with random bytes
    printf("%d\n", &t);
}	
