#ifndef DATA_H_ // To avoid multiple including
#define DATA_H_

// Raw data structure
typedef struct {
	int id; // Customer's id
	int day; // Day
	int at; // Arrival time
	int st; // Service begin time
	int et; // End time

} Raw;

// Processed data structure
typedef struct {
	int mean_s; // Queue mean size
	int max_s; // Queue max size
	int client_total; // Number of client during the day
	int angry_client; // Number of angry client
	int mean_service_time; // Mean service time
} Processed;

void print_raw(Raw * r);

void print_processed(Processed * p);

#endif