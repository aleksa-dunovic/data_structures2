/*
 * -------------------------
 * Student Name: Aleksa Dunovic
 * Student ID: 140271610
 * Student email: duno1610@mylaurier.ca
 * -------------------------
 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <assert.h>
# include "A8.h"

int min(int a, int b);
/*---------------------Task 1 -----------------------------*/
void schedule(char *type, Data *processes, const int size) {
//	assert(processes);
//	assert(size > -1);
	char fifo[5], sjf[4];
	strcpy(fifo, "FIFO");
	strcpy(sjf, "SJF");

	if (strcmp(type, fifo) != 0 && strcmp(type, sjf) != 0
			&& !(type[0] == 'R' && type[1] == 'R')) {
		printf("Error(schedule): Unsupported scheduler type\n");\
		return;
	}
	pQueue *q = create_pqueue(size, 'L');
	for (int i = 0; i < size; i++)
		insert_pqueue2(q, copy_data(&processes[i]));

	if (strcmp(type, fifo) == 0)
		schedule_FIFO(q);

	else if (strcmp(type, sjf) == 0)
		schedule_SJF(q);

	else if (type[0] == 'R' && type[1] == 'R')
		schedule_RR(q, atoi(type + 2));

	return;
}

/*---------------------Task 2 -----------------------------*/
void schedule_FIFO(pQueue *q) {

// Initialise timer, print starting statement, add one to timer, and create data object
	int timer = 0;
	printf("[Timer:%d]: Starting FIFO Scheduler\n", timer);
	timer++;
	Data *data;

// Loop through the queue until all processes are removed
	while (!is_empty_pqueue(q)) {

		// remove the process at the front of the queue
		data = remove_pqueue2(q);

		// If the process hasn't arrived yet print the idle statement and increase the timer
		while (timer < data->arrival) {
			printf("[Timer:%d]: Idle\n", timer);
			timer++;
		}

// If the process has arrived print the fetching statement and print the timer + proces info for the duration of the process
		if (timer >= data->arrival) {
			printf("Fetching Process: ");
			print_data(data);
			printf("\n");
			int count = 0;
			while (count <= data->time - 1) {
				printf("[Timer:%d]: ", timer);
				print_data(data);
				printf("\n");
				timer++;
				count++;
			}
		}
	}
// Print the closing statement
	printf("[Timer:%d]: Closing FIFO Scheduler\n", timer);
	return;
}

/*---------------------Task 3 -----------------------------*/
void schedule_SJF(pQueue *q) {

	Data *cache[q->capacity]; //temporarily store all arrived processes

//Initialise the timer, print starting statement, and add one to timer, and create data object
	int timer = 0;
	printf("[Timer:%d]: Starting SJF Scheduler\n", timer);
	timer++;
	Data *data;

//Fetch the next process
	while (!is_empty_pqueue(q)) { //Loop through the queue until all processes are removed

		// If a process hasn't arrived remove a process from the top of the queue
		if (peek_pqueue2(q)->arrival > timer)
			data = remove_pqueue2(q);
		else {

			// Add all arrived processes to the cache
			Data *removed; // stores the process temporarily
			int i = 0;
			while (peek_pqueue2(q)->arrival <= timer) {
				removed = remove_pqueue2(q);
				cache[i] = removed;
				i++;
				if (is_empty_pqueue(q))
					break;
			}

			// Find the process with the lowest processing time
			int min_indx = -1;
			Data *min = cache[0]; //process with lowest processing time
			min_indx = 0; //index of min in the cache
			for (int j = 1; j < i; j++) {
				if (cache[j]->time < min->time) {
					min = cache[j];
					min_indx = j;
				}
			}
			data = min; //assign min to the process we're going to use now

			// Push all other processes back onto the queue
			for (int j = 0; j < i; j++) {
				if (j != min_indx)
					insert_pqueue2(q, cache[j]);
			}

			// Clear Cache (not sure if this is necessary but it makes sure there are no other items in the cache from the previous iteration
			for (i = 0; i < q->capacity; ++i) {
				cache[i] = NULL;
			}
		}

//Print the process Log

// If the process hasn't arrived yet print the idle statement and increase the timer
		while (timer < data->arrival) {
			printf("[Timer:%d]: idle\n", timer);
			timer++;
		}

// If the process has arrived print the fetching statement and print the timer and process info for the duration of the process
		if (timer >= data->arrival) {
			printf("Fetching Process: ");
			print_data(data);
			printf("\n");
			int count = 0;
			while (count <= (data->time) - 1) {
				printf("[Timer:%d]: ", timer);
				print_data(data);
				printf("\n");
				timer++;
				count++;
			}
		}

	}
// Print the closing statement
	printf("[Timer:%d]: Closing SJF Scheduler\n", timer);
	return;
}

/*---------------------Task 4 -----------------------------*/
void schedule_RR(pQueue *q, int period) {
// Initialise timer, print starting statement, add one to timer, and create data object
	int timer = 0;
	printf("[Timer:%d]: Starting RR%d Scheduler\n", timer, period);
	timer++;
	Data *data;

//Loop through the queue until all processes are removed
	while (!is_empty_pqueue(q)) {
		//remove the processes by arrival time
		data = remove_pqueue2(q);

		// If the process hasn't arrived yet print the idle statement and increase the timer
		while (timer < data->arrival) {
			printf("[Timer:%d]: idle\n", timer);
			timer++;
		}

		// If the process has arrived print the fetch statement and print the timer + process info
		if (timer >= data->arrival) {
			printf("Fetching Process: ");
			print_data(data);
			printf("\n");
			int count = 0;

			// Serve the process until it's over or until the period limit is reached
			while (count <= min(period - 1, data->time - 1)) {
				printf("[Timer:%d]: ", timer);
				print_data(data);
				printf("\n");
				timer++;
				count++;
			}
			// The new arrival time becomes equal to the current time and subtract the service time from the process time
			data->arrival = timer;
			data->time -= count;
			// If the process isn't done (data->time !=0) push it back onto the queue for further processing
			if (data->time != 0)
				insert_pqueue2(q, data);
		}

	}
	// Print the closing statement
	printf("[Timer:%d]: Closing RR%d Scheduler\n", timer, period);
	return;
}

//helper function to find minimum of two numbers
int min(int a, int b) {
	if (a <= b)
		return a;
	if (b < a)
		return b;
	return 0;
}
