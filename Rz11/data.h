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

typedef int Data;

void print_data(Data *d);
void print_data_array(Data *array, const int size);
void destroy_data(Data **d);
Data* copy_data(Data *d1);
void swap_data(Data *d1, Data *d2);
int compare_data(Data *d1, Data *d2);

#endif /* DATA_H_ */
