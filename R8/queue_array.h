/*
 * -------------------------
 * Student Name: Aleksa Dunovic
 * Student ID: 140271610
 * Student email: duno1610@mylaurier.ca
 * -------------------------
 */

#ifndef QUEUE_ARRAY_H_
#define QUEUE_ARRAY_H_

#define True 1
#define False 0

#include "data.h"

typedef struct {
	Data *array; //array containing data items
	int front; //index of first item in Queue
	int rear; //index of last item in Queue
	int capacity; //maximum capacity of stack

} Queue;

Queue* create_queue(int capacity);
int is_empty_queue(Queue *q);
int len_queue(Queue *q);
int is_full_queue(Queue *q);
int insert_queue(Queue *q, Data *d);
Data* peek_queue(Queue *q);
Data* remove_queue(Queue *q);
void destroy_queue(Queue **q);
void print_queue(Queue *q);
int get_capacity_queue(Queue *q);

//Queue* copy_queue(Queue *s);

#endif /* QUEUE_ARRAY_H_ */
