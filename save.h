#ifndef SAVE_H_ // To avoid multiple including
#define SAVE_H_

#include "stack.h"

void save_raw(char * fname, Stack ** s);

void save_processed(char * fname, Processed * data);

void load_raw(char * fname, Stack ** s);

#endif