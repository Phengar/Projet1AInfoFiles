#include <stdio.h>
#include "data.h"

void print_raw(Raw * r) {
	printf("Raw : %d %d %d %d %d\n", r->id, r->day, r->at, r->st, r->et);
}

void print_processed(Processed * p) {
	printf("Processed : %d %d %d %d %d\n", p->mean_s, p->max_s, p->client_total, p->angry_client, p->mean_service_time);
}