#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "save.h"

#define path[] "raw.txt"

int lecture()

void main(){
	Raw data[10000];
	FILE *file;
	file = fopen("./raw.txt","r");
	if (file==NULL){
		exit("Can't open file!");
	}
	int i=0;
	while (fscanf(file, "%d %d %d %d %d\n", &data[i].id, &data[i].day, &data[i].at, &data[i].st, &data[i].et)!=-1){
		i++;
	}
	
}