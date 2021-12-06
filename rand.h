#ifndef RAND_H_ // To avoide multiple including
#define RAND_H_

void setSeed();

int random_int(int minserv, int maxserv);

double random_unif();

double random_expo(double lamb);

#endif