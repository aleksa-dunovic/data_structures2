/*
 * -------------------------
 * Student Name: Aleksa Dunovic
 * Student ID: 140271610
 * Student email: duno1610@mylaurier.ca
 * -------------------------
 */

#include "cqueue.h"

# include <stdio.h>
# include <stdlib.h>
# include <assert.h>

//int compare_data(Data *d1, Data *d2);
//int find_top_priority(pQueue *q);

cQueue* create_cqueue(int capacity) {
	cQueue *q = (cQueue*) malloc(sizeof(cQueue));
	if (capacity < 1) {
		printf("Error(create_cqueue): invalid cqueue capacity, set to 10\n");
		capacity = 10;
	}
	q->capacity = capacity;
	q->array = (Data*) malloc(sizeof(Data) * capacity);
	q->front = -1;
	q->rear = -1;
	q->size = 0;

	return q;
}
int is_empty_cqueue(cQueue *q) {
	assert(q!=NULL);
	return (q->size == 0);
}

int len_cqueue(cQueue *q) {
	assert(q!=NULL);
	return q->size;
}

int is_full_cqueue(cQueue *q) {
	assert(q!=NULL);
	return (q->size == q->capacity);
}

int insert_cqueue(cQueue *q, Data *d) {
	assert(q!= NULL && d!= NULL);
	if (is_full_cqueue(q)) {
		printf("Error(insert_cqueue): cqueue is full\n");
		return False;
	}

	if (is_empty_cqueue(q))
		q->front++;

	q->rear = (q->rear + 1) % q->capacity;
	q->array[q->rear] = *copy_data(d);
	q->size++;
	return True;
}

Data* peek_cqueue(cQueue *q) {
	assert(q!=NULL);
	if (is_empty_cqueue(q)) {
		printf("Error(peek_cqueue): cQueue is empty\n");
		return NULL;
	}
	return copy_data(&q->array[q->front]);
}
Data* remove_cqueue(cQueue *q) {
	assert(q!=NULL);
	Data *d = NULL;

	//empty queue
	if (is_empty_cqueue(q)) {
		printf("Error(remove_cqueue): cqueue is empty\n");
		return d;
	}

	//copy the item to be removed
	d = copy_data(&q->array[q->front]);

	//destroy the item
	Data *temp = &q->array[q->front];
	destroy_data(&temp);

	//update front in accordance to circular movement
	q->front = (q->front + 1) % q->capacity;
	//decrement size
	q->size--;

	//handle empty queues
	if (q->size == 0) {
		q->front = -1;
		q->rear = -1;
	}
	return d;
}

void destroy_cqueue(cQueue **q) {
	assert(q != NULL);
	while (!is_empty_cqueue(*q)) {
		Data *d = remove_cqueue(*q);
		destroy_data(&d);
	}
	free((*q)->array);
	(*q)->array = NULL;
	(*q)->capacity = 0;
	(*q)->rear = 0;
	(*q)->front = 0;
	(*q)->size = 0;
	free(*q);
	*q = NULL;
	return;

}
void print_cqueue(cQueue *q) {
	assert(q != NULL);
	int i;

	//print summary
	printf("Capacity = %d, Size = %d, front = %d, rear = %d\n", q->capacity,
			q->size, q->front, q->rear);

	//deal with empty queue;
	if (is_empty_cqueue(q))
		printf("<empty_cqueue>\n");

	else {
		int counter = 0;
		//loop for printing
		for (i = q->front; i < (q->front + q->size); i++) {

			print_data(&q->array[i % q->capacity]); //print

			//add line break if the end of the row is reached
			if ((counter + 1) % 5 == 0 && counter != len_cqueue(q) - 1)
				printf("\n");

			//add tabs between items unless it is the last item
			else if (counter != len_cqueue(q) - 1)
				printf("\t");

			counter++;

		}
		//only add a line break if the output doesn't fit on whole rows
		if (counter % 5 != 0)
			printf("\n");
	}
	return;
}

int get_capacity_queue(cQueue *q) {
	assert(q!=NULL);
	return q->capacity;
}
