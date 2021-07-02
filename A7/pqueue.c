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
	//your code here
	return NULL;
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
	//your code here
	return 0;
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
	//your code here
	return 0;
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
	//your code here
	return 0;
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
	//your code here
	return 0;
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
	//your code here
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
	//your code here
	return 0;
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
	//your code here
	return 0;
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
	//your code here
	return NULL;
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
	//your code here
	return NULL;
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
	//your code here
	return 0;
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
	//your code here
	return NULL;
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
	//your code
	return;
}
