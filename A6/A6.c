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
int is_equal_data(Data *d1, Data *d2);

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

//helper method to parse arrival without accessing data members directly
int get_arrival(Process *p) {
	char s[30];

	int arrival = 0;
	get_process_info(p, s);
	arrival = atoi(strtok(&s[1], "]("));

	return arrival;
}

//helper method to parse time without accessing data members directly
int get_time(Process *p) {
	char s[30];

	int time = 0;
	get_process_info(p, s);
	strtok(&s[0], ",");
	time = atoi(strtok(NULL, ")"));
	return time;
}

//helper method to parse PID without accessing data members directly
long get_PID(Process *p) {
	char s[30];
	char *ptr;

	int pid = 0;
	get_process_info(p, s);
	strtok(s, "(");
	pid = strtol(strtok(NULL, ","), &ptr, 10);
	return pid;
}

void reverse_stack(Stack *s) {
	assert(s!=NULL);
	int i, size = len_stack(s);
	Data *temp[size];

	// pop all elements to a temp array
	for (i = 0; i < size; i++) {
		temp[i] = pop_stack(s);
	}

	// put them back
	for (i = 0; i < size; i++) {
		push_stack(s, temp[i]);
	}

	return;
}

int contains_stack(Stack *s, Data *value) {
	//check for invalid stack
	if (!s) {
		printf("Error(contains_stack): invalid stack\n");
		return 0;
	}
	//check for invalid data
	if (!value) {
		printf("Error(contains_stack): invalid data\n");
		return 0;
	}

	//initialise vars
	int i, found = 0, counter = 0, size = len_stack(s);
	Data *temp[size];

	//pop all items to the temp array and check if a value is found.
	//stop when one is found
	for (i = 0; i < size; i++) {
		temp[i] = pop_stack(s);
		counter++;
		if (is_equal_data(temp[i], value)) {
			found = 1;
			break;
		}
	}
	//put the elements that we took back onto the stack
	for (i = 0; i < counter; i++) {
		push_stack(s, temp[i]);
	}

	return found;
}

int is_equal_data(Data *d1, Data *d2) {
	// I really don't agree with this approach. If we are also supposed to check if arrival matches
	// then this should be done in the process.c file and not here.
	if (is_equal_process(d1, d2) == 1 && (d2->arrival == d1->arrival)) {
		return 1;
	} else
		return 0;
}

int resize_stack(Stack *s, int new_capacity) {
//invalid inputs
	if (new_capacity < 1) {
		printf("Error(resize_stack): invalid capacity size.\n");
		return 0;
	}

	int size = len_stack(s);

//no resizing required
	if (size == new_capacity)
		return 0;

//Special Case: decreasing size
	if (size > new_capacity) {
		Data *temp;
		for (int i = 0; i < (size - new_capacity); i++) {
			if (peek_stack(s) != NULL) {
				temp = pop_stack(s);
				destroy_data(&temp);
			}
		}
	}

// update capacity and reallocate memory;
	s->capacity = new_capacity;
	s->array = (Data*) realloc(s->array, sizeof(Data) * s->capacity);

	return 1;
}
Stack* concat_stack(Stack *s1, Stack *s2) {
//create copies of the stack because I want to pop off the elements and leave the input stacks unchanged
	Stack *s11 = copy_stack(s1);
	Stack *s22 = copy_stack(s2);

//define the new capacity and create s3
	int capacity = s1->capacity + s2->capacity;
	Stack *s3 = create_stack(capacity);

//initialise variables
	int i, size1 = len_stack(s11), size2 = len_stack(s22), size = size1 + size2;
	Data *temp[size]; //to hold data that is popped off

//first we'll pop off all the elements in the second stack because it needs to be added last to the output stack
	for (i = 0; i < size2; i++)
		temp[i] = pop_stack(s22);

//then pop the elements from the first stack
	for (i = size2; i < size; i++)
		temp[i] = pop_stack(s11);

//add the elements to the new stack in reverse order.
	for (i = size - 1; i >= 0; i--)
		push_stack(s3, temp[i]);

//get rid of the copied stacks
	destroy_stack(&s11);
	destroy_stack(&s22);

	return s3;
}

