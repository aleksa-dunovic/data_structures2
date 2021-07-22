/*
 * -------------------------
 * Student Name: Aleksa Dunovic
 * Student ID: 140271610
 * Student email: duno1610@mylaurier.ca
 * -------------------------
 */

#ifndef DATA_H_
#define DATA_H_

#include "process.h"
#define True 1
#define False 0

typedef Process Data;

void print_data(Data *d);
void destroy_data(Data **d);
Data* copy_data(Data *d);
int compare_data(Data *d1, Data *d2);

#endif /* DATA_H_ */
