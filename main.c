#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "save.h"

int main() {
	/*Queue * q = NULL;
	push(&q);
	push(&q);
	push(&q);
	push(&q);
	push(&q);
	push(&q);
	print(&q);
	pop(&q);
	print(&q);
	pop(&q);
	print(&q);
	pop(&q);
	print(&q);
	pop(&q);
	print(&q);
	pop(&q);
	print(&q);
	pop(&q);
	print(&q);
	pop(&q);
	print(&q);
	return 0;*/
	char * fname_raw = "raw.txt";//, *fname_processed = "processed.txt";
	//Processed processed = {1, 2, 3, 4, 5};
	
	Raw data[2];
	/*data[0].id = 1;
	data[0].day = 2;
	data[0].at = 3;
	data[0].st = 4;
	data[0].et = 5;

	data[1].id = 6;
	data[1].day = 7;
	data[1].at = 8;
	data[1].st = 9;
	data[1].et = 10;*/

	//save_raw(fname_raw, data, 2);
	//save_processed(fname_processed, processed);
	load_raw(fname_raw, data, 2);
	printf("%d %d %d %d %d\n", data[0].id, data[0].day, data[0].at, data[0].st, data[0].et);
	return 0;
}