#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "save.h"

#define path "raw.txt"


void main(){
	Raw data[10000];
	FILE *file;
	file = fopen("./raw2.txt","r");
	if (file==NULL){
		printf("Can't open file!");
		return;
	}
	int i=0;
	while (fscanf(file, "%d %d %d %d %d\n", &data[i].id, &data[i].day, &data[i].at, &data[i].st, &data[i].et)!=-1){
		i++;
	}
	int nbp = i+1;
	int nbj = data[0].day;
	printf("nbp= %d nbp et nbj=%d\n", nbp, nbj);
	float nbpf = (float) nbp;
	float nbjf = (float) nbj;
	printf("nbpf= %f  et nbjf=%f\n", nbpf, nbjf);
	float djm = nbpf/nbjf;
	printf("The average number number of people per day is %f\n", djm);
}