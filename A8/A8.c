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

/*---------------------Task 1 -----------------------------*/
void schedule(char *type, Data *processes, const int size) {
//	assert(processes);
//	assert(size > -1);
	char fifo[5];
	strcpy(fifo, "FIFO");
//	if (strcmp(type,fifo" && type != "SJF") //&& (type[0] != 'R' && type[1] != 'R'))
//		printf("Error(schedule): Unsupported scheduler type");

	pQueue *q = create_pqueue(size, 'L');
	for (int i = 0; i < size; i++)
		insert_pqueue2(q, copy_data(&processes[i]));

	if (strcmp(type, fifo) == 0) {
		schedule_FIFO(q);
	}
	return;
}

/*---------------------Task 2 -----------------------------*/
void schedule_FIFO(pQueue *q) {

// Initialise timer, print starting statement, and add one to timer
	int timer = 0;
	printf("[Timer:%d]: Starting FIFO Scheduler\n", timer);
	timer++;

	Data *data;

	// Loop through the queue until all processes are removed
	while (!is_empty_pqueue(q)) {

		// remove the processes by arrival time
		data = remove_pqueue2(q);

		// If the process hasn't arrived yet print the idle statement and increase the timer
		while (timer < data->arrival) {
			printf("[Timer:%d]: Idle\n", timer);
			timer++;
		}

// If the process has arrived print the fetching statement and print the timer + PID for the duration of the process
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
//your code
	return;
}

/*---------------------Task 4 -----------------------------*/
void schedule_RR(pQueue *q, int period) {
//your code
	return;
}
