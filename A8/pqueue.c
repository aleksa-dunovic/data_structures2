/*
 * -------------------------
 * Student Name: Aleksa Dunovic
 * Student ID: 140271610
 * Student email: duno1610@mylaurier.ca
 * -------------------------
 */

# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
#include "pqueue.h"

int compare_data(Data *d1, Data *d2);
void adjust_queue(pQueue *q);
int find_top_priority(pQueue *q);

/**
 * ------------------------------------------------------------
 * Parameters: 	capacity: maximum size of priority queue
 * 				priority: a character describing priority mode
 * Returns: 	q: A pointer to a priority queue
 * Description:	Creates a priority queue
 * 				Dynamically creates an array of size: capacity
 * 				Sets front and rear to -1
 * 				priority is set to either 'H' or 'L'
 * 				if invalid capacity set to 10
 * 				if invalid priority set to 'H'
 * Assert:		None
 * Errors:		if invalid capacity:
 * 					Error(create_pqueue): invalid pqueue capacity, set to 10\n
 * 				if invalid priority:
 * 					"Error(create_pqueue): invalid priority, set to 'H'\n"
 * ------------------------------------------------------------
 */

pQueue* create_pqueue(int capacity, char priority) {
	pQueue *q = (pQueue*) malloc(sizeof(pQueue));
	if (capacity < 1) {
		printf("Error(create_pqueue): invalid pqueue capacity, set to 10\n");
		capacity = 10;
	}
	if (priority != 'H' && priority != 'L') {
		printf("Error(create_pqueue): invalid priority set to H\n");
		q->priority = 'H';
	} else
		q->priority = priority;
	q->capacity = capacity;
	q->array = (Data*) malloc(sizeof(Data) * capacity);
	q->front = -1;
	q->rear = -1;

	return q;

}

/**
 * ------------------------------------------------------------
 * Parameters: 	q: A pointer to a priority queue (pQueue*)
 * Returns: 	number of items in a pqueue (int)
 * Description:	Returns number of items in a pqueue
 * Assert:		q is not NULL
 * Errors:		None
 * ------------------------------------------------------------
 */
int len_pqueue(pQueue *q) {
	assert(q!=NULL);
	if (q->front == -1)
		return 0;
	return q->rear - q->front + 1;
}

/**
 * ------------------------------------------------------------
 * Parameters: 	q: A pointer to a priority queue (pQueue*)
 * Returns: 	pqueue capacity (int)
 * Description:	Returns maximum number of items that can be stored in a pqueue
 * Assert:		q is not NULL
 * Errors:		None
 * ------------------------------------------------------------
 */
int get_capacity_pqueue(pQueue *q) {
	assert(q!=NULL);
	return q->capacity;
}

/**
 * ------------------------------------------------------------
 * Parameters: 	q: A pointer to a priority queue (pQueue*)
 * Returns: 	True/False (int)
 * Description:	Returns True if pqueue is empty, False otherwise
 * Assert:		q is not NULL
 * Errors:		None
 * ------------------------------------------------------------
 */
int is_empty_pqueue(pQueue *q) {
	assert(q!=NULL);
	return (len_pqueue(q) == 0);

}

/**
 * ------------------------------------------------------------
 * Parameters: 	q: A pointer to a priority queue (pQueue*)
 * Returns: 	True/False (int)
 * Description:	Returns True if pqueue is full, False otherwise
 * Assert:		q is not NULL
 * Errors:		None
 * ------------------------------------------------------------
 */
int is_full_pqueue(pQueue *q) {
	assert(q!=NULL);
	return (len_pqueue(q) == q->capacity);
}

/**
 * ------------------------------------------------------------
 * Parameters: 	q: A pointer to a priority queue (pQueue*)
 * Returns: 	None
 * Description:	Prints contents of a priority queue
 * 				Starts with:
 * 					Capacity = <int>, Size = <int>, front = <int>, rear = <int>\n
 * 				Then prints queue elements separated by a tab
 * 				Each five elements appear on a separate line
 * 				if empty prints: <empty_pqueue>\n
 * Assert:		q is not NULL
 * Errors:		None
 * ------------------------------------------------------------
 */
void print_pqueue(pQueue *q) {
	assert(q!=NULL);
//	assert(!q);
	int i;
	printf("Capacity = %d, Size = %d, front = %d, rear = %d\n", q->capacity,
			len_pqueue(q), q->front, q->rear);
	if (is_empty_pqueue(q))
		printf("<empty_pqueue>\n");
	else {
		int counter = 0;
		for (i = q->front; i <= q->rear; i++) {
			print_data(&q->array[i]);
			if ((counter + 1) % 5 == 0 && counter != len_pqueue(q) - 1)
				printf("\n");
			else
				printf("\t");
			counter++;

		}
		printf("\n");
	}
	return;
}

/**
 * ------------------------------------------------------------
 * Parameters: 	q: A pointer to a priority Queue (pQueue*)
 * 				d: A data item to be added (Data*)
 * Returns: 	True/False
 * Description:	Insert an item to the queue (unsorted insertion)
 * 				returns True if insert is successful and False otherwise
 * Assert:		q and d are not NULL
 * Errors:		if full --> Error(insert_pqueue): pqueue is full\n
 * Analysis: 	O(n) if regular queue
 * 				O(1) if circular queue
 * ------------------------------------------------------------
 */
int insert_pqueue(pQueue *q, Data *d) {
	assert(q!=NULL && d!=NULL);
	if (is_full_pqueue(q)) {
		printf("Error(insert_pqueue): pqueue is full\n");
		return False;
	}
	if (is_empty_pqueue(q))
		q->front = 0;
	else if (q->rear == q->capacity - 1)
		adjust_queue(q);
	q->rear++;
	q->array[q->rear] = *copy_data(d);
	return True;
}

/**
 * ------------------------------------------------------------
 * Parameters: 	q: A pointer to a priority Queue (pQueue*)
 * 				d: A data item to be added (Data*)
 * Returns: 	True/False
 * Description:	Insert an item to the queue (sorted insertion)
 * 				returns True if insert is successful and False otherwise
 * Assert:		q and d are not NULL
 * Errors:		if full --> Error(insert_pqueue): pqueue is full\n
 * Analysis: 	O(n)
 * ------------------------------------------------------------
 */
int insert_pqueue2(pQueue *q, Data *d) {
	assert(q!=NULL && d!=NULL);

	//queue is full
	if (is_full_pqueue(q)) {
		printf("Error(insert_pqueue2): pqueue is full\n");
		return False;
	}

	//queue is empty
	if (is_empty_pqueue(q)) {
		q->front = 0;
		q->rear++;
		q->array[q->rear] = *copy_data(d);
		return True;

	}

	if (q->rear == q->capacity - 1)
		adjust_queue(q);

	int indx = 0, found = 0;
	//find index of insertion spot in H priority queue
	if (q->priority == 'H') {
		for (int i = q->front; i <= q->rear; i++) {
			if (compare_data(d, &q->array[i]) == 1) {
				found = 1;
				indx = i;
				break;
			}
		}
	}
	//find index of insertion spot in L priority queue
	else if (q->priority == 'L') {
		for (int i = q->front; i <= q->rear; i++) {
			if (compare_data(d, &q->array[i]) == 2) {
				found = 1;
				indx = i;
				break;
			}
		}
	}
//		print_data(d);
//		printf("\n");
//		printf("THIS IS THE INDEX %d\n", indx);
	if (found == 1) {
		//adjust queue
		for (int i = q->rear; i >= indx; i--) {
			q->array[i + 1] = q->array[i];
		}
		//add new data and move rear
		q->array[indx] = *copy_data(d);
		q->rear++;
	} else {
		q->rear++;
		q->array[q->rear] = *copy_data(d);
	}

	return True;

}

/**
 * ------------------------------------------------------------
 * Parameters: 	q: A pointer to a priority Queue (pQueue*)
 * Returns: 	d: a copy of data item at the front of pqueue
 * Description:	Returns a copy of front of pqueue
 * 				Assumes unsorted insert
 * Assert:		q is not NULL
 * Errors:		if empty --> Error(peek_pqueue): pqueue is empty\n
 * Analysis: 	O(n)
 * ------------------------------------------------------------
 */
Data* peek_pqueue(pQueue *q) {
	assert(q!=NULL);
	if (is_empty_pqueue(q)) {
		printf("Error(peek_pqueue): pqueue is empty\n");
		return NULL;
	}
//	if (len_pqueue(q) == 1)
//		return copy_data(&q->array[q->front]);
	return copy_data(&q->array[find_top_priority(q)]);
}

/**
 * ------------------------------------------------------------
 * Parameters: 	q: A pointer to a priority Queue (pQueue*)
 * Returns: 	d: a copy of data item at the front of pqueue
 * Description:	Returns a copy of front of pqueue
 * 				Assumes sorted insert
 * Assert:		q is not NULL
 * Errors:		if empty --> Error(peek_pqueue): pqueue is empty\n
 * Analysis: 	O(1)
 * ------------------------------------------------------------
 */
Data* peek_pqueue2(pQueue *q) {
	assert(q!=NULL);
	if (is_empty_pqueue(q)) {
		printf("Error(peek_pqueue2): pqueue is empty\n");
		return NULL;
	}
	return copy_data(&q->array[q->front]);
}

/**
 * ------------------------------------------------------------
 * Parameters: 	q: A pointer to a priority Queue (pQueue*)
 * Returns: 	d: a copy of data item at the front of pqueue
 * Description:	Returns a copy of front of pqueue
 * 				Assumes unsorted insert
 * Assert:		q is not NULL
 * Errors:		if empty --> Error(remove_pqueue): pqueue is empty\n
 * Analysis: 	O(n)
 * ------------------------------------------------------------
 */
Data* remove_pqueue(pQueue *q) {
	assert(q!=NULL);
	Data *d = NULL;
	if (is_empty_pqueue(q)) {
		printf("Error(remove_queue): queue is empty\n");
		return d;
	}

	int indx = find_top_priority(q);
//	printf("this is the index: %d\n", indx);
	d = copy_data(&q->array[indx]);
	Data *temp = &q->array[indx];
	destroy_data(&temp);

	if (len_pqueue(q) == 1) {
		q->front = -1;
		q->rear = -1;
	} else {

		//Case 1: removing the front of the queue
		if (indx == q->front)
			q->front++;

		//Case 2: removing the rear of the queue
		else if (indx == q->rear)
			q->rear--;

		//Case 3: removing in the middle of the queue
		else {

			for (int i = indx; i <= q->rear; i++) {
				q->array[i] = q->array[i + 1];
			}
			q->rear--;
		}
	}
	return d;

}

/**
 * ------------------------------------------------------------
 * Parameters: 	q: A pointer to a priority Queue (pQueue*)
 * Returns: 	d: a copy of data item at the front of pqueue
 * Description:	Returns a copy of front of pqueue
 * 				Assumes sorted insert
 * Assert:		q is not NULL
 * Errors:		if empty --> Error(remove_pqueue2): pqueue is empty\n
 * Analysis: 	O(1)
 * ------------------------------------------------------------
 */
Data* remove_pqueue2(pQueue *q) {
	assert(q!=NULL);
	Data *d = NULL;
	if (is_empty_pqueue(q)) {
		printf("Error(remove_pqueue): pqueue is empty\n");
		return d;
	}
	d = copy_data(&q->array[q->front]);

	Data *temp = &q->array[q->front];
	destroy_data(&temp);
	q->front++;

	if (len_pqueue(q) == 0) {
		q->front = -1;
		q->rear = -1;
	}
	return d;
}

/**
 * ------------------------------------------------------------
 * Parameters: 	q: A double pointer to a priority Queue (pQueue**)
 * Returns: 	None
 * Description:	Destroy a queue by:
 * 					removing and destroying all data items
 * 					freeing queue array
 * 					set all other data members to 0
 * 					free queue
 * 				Assumes sorted insert
 * Assert:		q is not NULL
 * Errors:		None
 * ------------------------------------------------------------
 */
void destroy_pqueue(pQueue **q) {
	assert(q!=NULL);
	while (!is_empty_pqueue(*q)) {

		Data *d = remove_pqueue(*q);
		destroy_data(&d);
	}

	free((*q)->array);
	(*q)->array = NULL;
	(*q)->capacity = 0;
	(*q)->rear = 0;
	(*q)->front = 0;
	(*q)->priority = 0;
	free(*q);
	*q = NULL;
	return;
}

//int compare_data(Data *d1, Data *d2) {
//	if (d1->time > d2->time)
//		return 1;
//	else if (d1->time < d2->time)
//		return 2;
//	else if (d1->time == d2->time) {
//		if (d1->arrival > d2->arrival)
//			return 1;
//		else if (d1->arrival < d2->arrival)
//			return 2;
//		else if (d1->arrival == d2->arrival) {
//			if (d1->PID > d2->PID)
//				return 1;
//			else if (d1->PID < d2->PID)
//				return 2;
//		}
//	}
//	return 0;
//}

void adjust_queue(pQueue *q) {
	assert(q!=NULL);
	int length = len_pqueue(q), i;
	for (i = 0; i < length; i++)
		q->array[i] = q->array[i + q->front];
	q->front = 0;
	q->rear = length - 1;

}

/**
 * ------------------------------------------------------------
 * Parameters: q: A pointer to a priority Queue (pQueue*)
 * Returns: index: index of top priority item
 * Description: A private helper function mainly for unsorted
 * insertion pqueue
 * finds index of item with highest priority in pqueue
 * if 'H' --> finds largest value
 * if 'L' --> finds smallest value
 * Assert: q is not NULL
 * q is not empty
 * Errors: None
 * Analysis: O(n)
 * ------------------------------------------------------------
 */
int find_top_priority(pQueue *q) {
	assert(q!=NULL);
	assert(!is_empty_pqueue(q));
	int i, indx = 0;

	if (len_pqueue(q) == 1)
		return q->front;

	if (q->priority == 'H') {
		Data *max = &q->array[q->front];
		for (i = q->front; i <= q->rear; i++) {
//			print_data(&q->array[i]);
//			printf("\n");

			if (compare_data(&q->array[i], max) == 1) {
				max = &q->array[i];
				indx = i;
			}

		}
//		printf("MAXXX: ");
//		print_data(max);
	} else {
		Data *min = &q->array[q->front];
		for (i = q->front; i <= q->rear; i++) {
			if (compare_data(&q->array[i], min) == 2) {
				min = &q->array[i];
				indx = i;
			}
		}
	}
	return indx;
}

