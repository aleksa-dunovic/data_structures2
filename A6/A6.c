/*
 * -------------------------
 * Student Name: Aleksa Dunovic
 * Student ID: 140271610
 * Student email: duno1610@mylaurier.ca
 * -------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "A6.h"
#include "process.h"

int get_arrival(Process *p);
int get_time(Process *p);
long get_PID(Process *p);

//int main() {
//	Process *processes = NULL;
//	processes = (Process*) malloc(sizeof(Process) * 6);
//	processes[0] = (Process ) { 111111, 20, 5 };
//	processes[1] = (Process ) { 222222, 10, 7 };
//	processes[2] = (Process ) { 333333, 60, 7 };
//	processes[3] = (Process ) { 444444, 20, 8 };
//	processes[4] = (Process ) { 555555, 30, 9 };
//	processes[5] = (Process ) { 666666, 30, 9 };
//
//	printf("Arrival: %d\n", get_arrival(&processes[0]));
//	printf("PID: %lu\n", get_PID(&processes[0]));
//	printf("Time: %d\n", get_time(&processes[0]));
//
//	free(processes);
//	processes = NULL;
//	return 0;
//}

void remove_shortest(Process *processes, const int size) {

	// null process pointer
	if (processes == NULL) {
		printf("Error(remove_shortest): given pointer is NULL\n");
		return;
	}

	// invalid size of process array
	if (size <= 0) {
		printf("Error(remove_shortest): invalid array size\n");
		return;
	}

	//initialise variables
	int i, indx = 0;
	Process *min;
	min = &processes[0];

	// special case of single data member
	if (size == 1) {
		printf("Shortest Process is : %lu\n", get_PID(&processes[indx]));
		processes->PID = 0;
		processes->time = 0;
		processes->arrival = 0;

		return;
	}

	// all other cases
	for (i = 1; i < size; i++) {
		//current has shorter duration
		if (get_time(min) > get_time(&processes[i])) {
			min = &processes[i];
			indx = i;
			//equivalent time duration
		} else if (get_time(min) == get_time(&processes[i])) {
			//current has sooner arrival
			if (get_arrival(min) > get_arrival(&processes[i])) {
				min = &processes[i];
				indx = i;
				//equivalent arrival
			} else if (get_arrival(min) == get_arrival(&processes[i])) {
				//finally check PIDs
				if (get_PID(min) > get_PID(&processes[i])) {
					min = &processes[i];
					indx = i;
				}
			}
		}
	}

	printf("Shortest Process is : %lu\n", get_PID(&processes[indx]));

	//shift all items over
	processes[indx] = processes[size - 1];

	//update the pointer if we're removing the first process
	if (indx == 0) {
		processes = &processes[0];
	}

//resize
	processes = (Process*) realloc(processes, sizeof(Process) * (size - 1));

	return;
}

void reverse_stack(Stack *s) {
//your code here
	return;
}

int contains_stack(Stack *s, Data *value) {
//your code here
	return 0;
}

int resize_stack(Stack *s, int new_capacity) {
//your code here
	return 0;
}
Stack* concat_stack(Stack *s1, Stack *s2) {
//your code here
	return NULL;
}

int get_arrival(Process *p) {
	char s[30];

	int arrival = 0;
	get_process_info(p, s);
	arrival = atoi(strtok(&s[1], "]("));

	return arrival;
}

int get_time(Process *p) {
	char s[30];

	int time = 0;
	get_process_info(p, s);
	strtok(&s[0], ",");
	time = atoi(strtok(NULL, ")"));
	return time;
}

long get_PID(Process *p) {
	char s[30];
	char *ptr;

	int pid = 0;
	get_process_info(p, s);
	strtok(s, "(");
	pid = strtol(strtok(NULL, ","), &ptr, 10);
	return pid;
}

