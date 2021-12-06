#ifndef DATA_H_ // To avoid multiple including
#define DATA_H_

// Raw data structure - contains data that defines a customer
typedef struct {
	int id; // Customer's id
	int day; // Day
	int at; // Arrival time
	int st; // Service begin time
	int et; // End time

} Raw;

// Processed data structure - contains statistics related to the simulation
typedef struct {
	double mean_s; // Queue mean size
	int max_s; // Queue max size
	double client_rate; // Client rate through the day
	double client_both; // Bothered (Unserved) clients rate
	double mean_response_time; // Mean service time
} Processed;

void print_raw(Raw * r);

void print_processed(Processed * p);

void init_processed(Processed * p);

void free_raw(Raw * r);

void free_processed(Processed * p);

#endif