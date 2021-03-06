/*
	main.c - Main program that implements the whole queue simulation logic
*/

// by DAVAL Quentin - HUBINET Benjamin - ISMIN 1A - EI21

////////////////////////////////////////////////////////////////////////////////////////
// Mandatory includes
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"
#include "save.h"
#include "data.h"
#include "rand.h"
////////////////////////////////////////////////////////////////////////////////////////
// Constants
#define DAY_LENGTH 32400 // 9 Hours // In seconds
#define HOST_TIME_LIMIT 30600 // 8h30 after opening, the queue no longer accepts new clients
////////////////////////////////////////////////////////////////////////////////////////
int min2sec(double minutes);
double seconds(double seconds);
void simulate(int days);
void disp_menu();
void menu();
////////////////////////////////////////////////////////////////////////////////////////
// Auxiliary functions


// Converts minutes into seconds
int min2sec(double minutes) {
	return (int) (60 * minutes);
}

// Converts seconds into minutes
double sec2min(double seconds) {
	return seconds / 60;
}

////////////////////////////////////////////////////////////////////////////////////////
// Simulates the whole queue logic. Please note that every actual_time will be expressed
// in seconds for computation conveniency
void simulate(int days) {
	/*
		actual_time : current day actual time,
		client_id   : new client id
		lambda, minserv, maxserv : parameters for random number generators
		tmp_at : New client temporary arrival time
		tmp_mean_response_time : used to precompute mean service time
		client_served : Number of client served during the day
		remain_time : remain service time of the current client client
		last_at : Arrival time of the last client
		queue_size : Current queue size;
	*/
	printf("Launching simulation...\n");
	int actual_time = 0, client_id = 1;
	double lambda, minserv, maxserv, temp_double;
	int tmp_at = 0, tmp_mean_response_time  = 0, client_served = 0;
	int remain_time = 0, last_at = 0, queue_size = 0;

	//////// Statistics Init ////////
	Processed stats;
	init_processed(&stats);
	/////////////////////////////////

	Queue * q = NULL; // Client stack
	Stack * s = NULL; // To trace every client

	Raw * r = NULL; // Pointer to current client's data

	//////// Parameters for the simulation ////////
	printf("Please enter minserv maxserv in minutes :\n");
	printf(">>");
	scanf("%lf", &minserv);
	scanf("%lf", &maxserv);
	minserv = min2sec(minserv); // Entering them as minutes is easier (in my opinion)
	maxserv = min2sec(maxserv);
	printf("Please enter the frequency (lambda) between each client :\n");
	printf(">>");
	scanf("%lf", &lambda);

	setSeed(); // Sets simulation seed

	
	for(int day = 1; day <= days; day++) {
		while(actual_time < DAY_LENGTH) {
			
			//printf("<Time : %d>\n", actual_time);

			//////// Incoming clients generation ////////
			if(last_at < HOST_TIME_LIMIT && actual_time>last_at) { // New customers can come in

				temp_double = random_expo(lambda); // Tries to generate the new client arrival time
					tmp_at = (int) temp_double;
					//("double value: %lf s, int value %d s.\n",temp_double,tmp_at); 

				if(tmp_at + last_at <= HOST_TIME_LIMIT) { // Able to generate a customer

					

					queue_size++; // A new customer pops in, the queue length increases
					r = (Raw *) malloc(sizeof(Raw));
					if(r == NULL) { // Error handling
						printf("Simulation error - Cannot allocate memory.\n");
						return;
					}
					// Loading client informations
					r->id = client_id;
					r->day = day;
					r->at = last_at + tmp_at;
					r->st = random_int(minserv, maxserv);
					r->et = -1; // Not known yet
					push_queue(&q, r); // Adding the new client to queue

					//printf("Actual time: %ds, time taken after previous client: %ds, time of service:%d s, number of people in line: %d\n", actual_time, tmp_at, r->st, queue_size);
					
					client_id++;
					last_at = r->at; // The new client becomes the "next" last added client
					//printf("[+] Client : id: %d  day: %d  at: %d  st: %d  et: %d\n", r->id, r->day, r->at, r->st, r->et);
				}else{
					last_at=HOST_TIME_LIMIT+1;
				}
			}
			remain_time --;
			/////////////////////////////////////////////
			//// Statistics
			if(stats.max_s < queue_size-1) { // Calculating max queue size
				stats.max_s = queue_size-1;
			}

			if(!(actual_time % 10)) { // Sampling each 10s current queue size
				stats.mean_s += queue_size;
			}
			////
			////////////// Serving clients //////////////
			if(q != NULL) { // If queue is not empty
				if(remain_time <= 0 && q->data->at <= actual_time) {
					//// Statistics
					tmp_mean_response_time += actual_time - q->data->at;
					client_served++;

					////
					//printf("[++] Treating client : id: %d\n", q->data->id);
					remain_time = q->data->st; // The service begins
					pop_queue(&q, &s);
					queue_size--;
					s->data->et = actual_time; // Setting previous client end time
				} 
			}
			/////////////////////////////////////////////
			actual_time++;
		}
		//////// New day resets ////////
		//// Statistics update
		stats.client_rate += client_id - 1;
		stats.mean_response_time += ((double) tmp_mean_response_time) / ((double) client_served);
		stats.client_both += 1 - ((double) client_served) / ((double) (client_id -1));//((double) size_queue(&q)) / ((double) (client_id - 1));
		////
		// Reseting some datas for the next day
		actual_time = 0;
		queue_size = 0;
		client_id = 1;
		remain_time = 0;
		last_at = 0;
		tmp_mean_response_time = 0;
		client_served = 0;
		free_queue(&q, &s); // Deletes the unserved client of the queue
		////////////////////////////////
	}


	//////// Final Statistics ////////
	stats.mean_s /= (((double) days) * (((double) DAY_LENGTH) / 10)); // Divided by 10 comes from the sampling rate
	stats.client_both /= (double) days;
	stats.mean_response_time /= (double) days; // that's the mean of mean response times
	stats.client_rate /= (double) days;

	stats.mean_response_time = sec2min(stats.mean_response_time);
	///////// Printing Stats /////////
	print_processed(&stats);
	//////////////////////////////////

	//// Saving raw data /////
	char fname[100]; // raw file name
	printf("\nEnter the file name to save raw data in :\n");
	printf(">>");
	scanf("%s", fname);
	save_raw(fname, &s); // Saving raw data
	free_stack(&s); // Final RAM clear
}

////////////////////////////////////////////////////////////////////////////////////////

// Displays the user interfaces
void disp_menu() {
	printf("======== Checkout line simulator ========\n");
	printf(" 1. One day simulation\n");
	printf(" 2. N days simulation\n");
	printf(" 0. Quit\n");
	printf("=========================================\n");
	printf(">> ");
}

// Handles the menu interface
void menu() {
	int i = -1;
	int days = 1;
	while(i != 0) { // Type 0 in menu to stop the program
		disp_menu();
		scanf("%d", &i);
		switch(i) {
			case 1:
				simulate(days);
			break;
			case 2:
				printf("Please enter the number of days :\n");
				printf(">>");
				scanf("%d", &days);
				simulate(days);
			break;
		}
		printf("\n");
	}
	printf("by DAVAL Quentin - HUBINET Benjamin - ISMIN 1A - EI21\n");
}

////////////////////////////////////////////////////////////////////////////////////////

int main() {
	menu();
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////