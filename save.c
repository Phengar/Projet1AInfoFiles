/*
	Save.c - As stated, saves raw and processed simulation data in .txt files
*/

#include <stdio.h>
#include <stdlib.h>
#include "save.h"

// Saves raw data array into .txt file
void save_raw(char * fname, Stack ** s) {
	FILE * file = fopen(fname, "w");
	if(file == NULL) {
		printf("Cannot open the file.\n");
		return;
	}
	Stack * curr = *s;
	while(curr != NULL) {
		fprintf(file, "%d %d %d %d %d\n", curr->data->id, curr->data->day, curr->data->at, curr->data->st, curr->data->et);
		curr = curr->next;
	}
	fclose(file);
}

// Saves processed data into .txt file
void save_processed(char * fname, Processed * data) {
	FILE * file = fopen(fname, "w");
	if(file == NULL) {
		printf("Cannot open the file.\n");
		return;
	}
	fprintf(file, "%d %d %d %d %d", data->mean_s, data->max_s, data->client_total, data->angry_client, data->mean_service_time);
	fclose(file);
}

// Loads raw data array from .txt file
void load_raw(char * fname, Stack ** s) {
	printf("I'm alive\n");
	FILE * file = fopen(fname, "r");
	if(file == NULL) {
		printf("Cannot open the file.\n");
		return;
	}
	int endOfFile = 0;
	Raw * tmp = (Raw *) malloc(sizeof(Raw));
	if(tmp == NULL) { // Handles allocation issues
		printf("Cannot allocate memory.\n");
		return;
	}
	while(endOfFile != -1) {
		endOfFile = fscanf(file, "%d %d %d %d %d\n", &tmp->id, &tmp->day, &tmp->at, &tmp->st, &tmp->et);
		printf("%d %d %d %d %d %d\n", endOfFile, tmp->id, tmp->day, tmp->at, tmp->st, tmp->et);
		if(endOfFile != -1) {
			push_stack(s, tmp);
			printf("STP : ");
			print_raw(tmp);
		}
	}
	fclose(file);
}