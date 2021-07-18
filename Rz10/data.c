/*
 * -------------------------
 * Student Name: Aleksa Dunovic
 * Student ID: 140271610
 * Student email: duno1610@mylaurier.ca
 * -------------------------
 */

#include "data.h"

void print_data(Data *d) {
	print_process(d);
	return;
}
void destroy_data(Data **d) {
	destroy_process(d);
	return;
}
Data* copy_data(Data *d) {
	return copy_process(d);
}
