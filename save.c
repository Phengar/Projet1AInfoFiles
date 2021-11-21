/*
	Save.c - As stated, saves raw and processed simulation data in .txt files
*/

#include <stdio.h>
#include "save.h"

// Raw data structure
struct raw {
	int id; // Customer's id
	int day; // Day
	int at; // Arrival time
	int st; // Service begin time
	int et; // End time

};

// Processed data structure
struct processed {
	int mean_s; // Queue mean size
	int max_s; // Queue max size
	int client_total; // Number of client during the day
	int angry_client; // Number of angry client
	int mean_service_time; // Mean service time
};


// Saves raw data array into .txt file
void save_raw(char * fname, Raw * data, int size) {
	FILE * file = fopen(fname, "w");
	if(file == NULL) {
		printf("Cannot open the file.\n");
		return;
	}
	for(int i = 0; i < size; i++) {
		fprintf(file, "%d %d %d %d %d\n", data[i].id, data[i].day, data[i].at, data[i].st, data[i].et);
	}
	fclose(file);
}

// Saves processed data into .txt file
void save_processed(char * fname, Processed data) {
	FILE * file = fopen(fname, "w");
	if(file == NULL) {
		printf("Cannot open the file.\n");
		return;
	}
	fprintf(file, "%d %d %d %d %d", data.mean_s, data.max_s, data.client_total, data.angry_client, data.mean_service_time);
	fclose(file);
}

// Loads raw data array from .txt file
void load_raw(char * fname, Raw * data, int size) {
	FILE * file = fopen(fname, "r");
	if(file == NULL) {
		printf("Cannot open the file.\n");
		return;
	}
	for(int i = 0; i < size; i++) {
		fscanf(file, "%d %d %d %d %d\n", &data[i].id, &data[i].day, &data[i].at, &data[i].st, &data[i].et);
	}
	fclose(file);
}

/*
int main() {
	char * fname_raw = "raw.txt", *fname_processed = "processed.txt";
	Processed processed = {1, 2, 3, 4, 5};
	
	Raw data[2];
	data[0].id = 1;
	data[0].day = 2;
	data[0].at = 3;
	data[0].st = 4;
	data[0].et = 5;

	data[1].id = 6;
	data[1].day = 7;
	data[1].at = 8;
	data[1].st = 9;
	data[1].et = 10;

	save_raw(fname_raw, data, 2);
	save_processed(fname_processed, processed);
	load_raw(fname_raw, data, 2);
	printf("%d %d %d %d %d\n", data[0].id, data[0].day, data[0].at, data[0].st, data[0].et);
	return 0;
}*/