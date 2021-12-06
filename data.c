/*
	data.c - Implements structures, display function and free function for 
*/

#include <stdio.h>
#include <stdlib.h>
#include "data.h"

// Prints raw structure : (For debug)
void print_raw(Raw * r) {
	printf("Raw : %d %d %d %d %d\n", r->id, r->day, r->at, r->st, r->et);
}

// Prints processed structure - Displays statistics at the end of the simulation
void print_processed(Processed * p) {
	printf("\n>>>>>>>>>>>>> Statistics <<<<<<<<<<<<<<\n");
	printf("-> mean queue size: %lf\n", p->mean_s);
	printf("-> max queue size: %d\n", p->max_s);
	printf("-> clients per day: %lf\n", p->client_rate);
	printf("-> Unserved clients rate: %lf\n",  p->client_both);
	printf("-> Mean response time: %lf min\n", p->mean_response_time);
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}

// Inits a processed structure
void init_processed(Processed * p) {
	p->mean_s = 0.0;
	p->max_s = 0;
	p->client_rate = 0.0;
	p->client_both = 0.0;
	p->mean_response_time = 0.0;
}

// Frees raw structure from memory
void free_raw(Raw * r) {
	free(r);
}

// Frees processed structure from memory
void free_processed(Processed * p) {
	free(p);
}