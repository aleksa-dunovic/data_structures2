/*
 * -------------------------
 * Student Name: Aleksa Dunovic
 * Student ID: 140271610
 * Student email: duno1610@mylaurier.ca
 * -------------------------
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

Node* get_node(List *l, int indx);

Node* create_node(Data *d, Node *n) {
	assert(d);
	Node *node = (Node*) malloc(sizeof(Node));
	node->data = copy_data(d);
	node->next = n;
	return node;
}

void destroy_node(Node **n) {
	assert(n && *n);
	destroy_data(&(*n)->data);
	(*n)->data = NULL;
	(*n)->next = NULL;
	free(*n);
	return;

}
void print_node(Node *n) {
	assert(n);
	print_data(n->data);
	return;
}
Node* copy_node(Node *n) {
	assert(n);
	return create_node(n->data, n->next);
}

List* create_list() {
	List *list = (List*) malloc(sizeof(List));
	list->head = NULL;
	list->size = 0;
	return list;
}

void print_list(List *list) {
	assert(list);
	Node *current_node = list->head;
	while (current_node != NULL) {
		print_node(current_node);
		printf("-->");
		current_node = current_node->next;
	}
	printf("NULL\n");
	return;
}

void destroy_list(List **list) {
	assert(list && *list);
	while ((*list)->size > 0) {
		pop_list(*list, 0);
	}
	(*list)->head = NULL;
	(*list)->size = 0;
	free(*list);
	return;
}

Data* pop_list(List *list, int index) {
	assert(list!=NULL);
	//error checking
	if (list->size == 0) {
		printf("Error(pop_list): list is empty\n");
		return False;
	}

	if (index < 0 || index >= list->size) {
		printf("Error(pop_list): index out of range\n");
		return False;
	}

	Data *d;
	if (list->size == 1) {						//list with only one item
		d = copy_data(list->head->data);
		destroy_node(&list->head);
		list->head = NULL;

	} else if (index == 0) {					//popping head
		d = copy_data(list->head->data);
		Node *new_head = list->head->next;
		destroy_node(&list->head);
		list->head = new_head;
	} else if (index == list->size - 1) {		//popping last item
		Node *previous = get_node(list, index);
		d = copy_data(previous->next->data);
		destroy_node(&previous->next);
		previous->next = NULL;
	} else {									//all other cases
		Node *previous = get_node(list, index);
		Node *temp = previous->next->next;
		d = copy_data(previous->next->data);
		destroy_node(&previous->next);
		previous->next = temp;
	}

	list->size--;
	return d;
}

void append_list(List *list, Data *d) {
	assert(list && d);
	Node *new_node = create_node(d, NULL);
	if (list->head == NULL)
		list->head = new_node;
	else {
		Node *current_node = list->head;
		while (current_node->next != NULL)
			current_node = current_node->next;
		current_node->next = new_node;
	}
	list->size++;
	return;
}

/**
 * ---------------------------------------------------------------------
 * Parameters: a pointer to a linked list (List*)
 * Returns: None
 * Description: removes first item from linked list
 * if list is empty, prints error msg and returns NULL
 * Asserts: asserts given linked list is not Null
 * ---------------------------------------------------------------------
 */
Data* remove_front_list(List *list) {
	assert(list!= NULL);
	if (list->size == 0) {
		printf("Error(remove_front_list): list is empty\n");
		return NULL;
	}

	Data *removed = copy_data(list->head->data);
	Node *current = list->head;
	list->head = list->head->next;
	list->size--;
	destroy_node(&current);

	return removed;
}
void insert_front_list(List *list, Data *d) {
	assert(list!=NULL && d!=NULL);
	Node *new_node = create_node(d, list->head);
	list->head = new_node;
	list->size++;
}

Node* get_node(List *l, int indx) {
	//fetches note at indx -1
	Node *current = l->head;
	int counter = 0;
	while (current == NULL || counter < indx - 1) {
		current = current->next;
		counter++;
	}

	return current;
}

/**
 * ---------------------------------------------------------------------
 * Parameters: a pointer to a linked list (List*)
 * Returns: Copy of data stored in first node (Data*)
 * Description: returns copy of data stored in first node
 * if list is empty, prints error msg and returns NULL
 * Asserts: asserts given linked list is not Null
 * ---------------------------------------------------------------------
 */

Data* peek_list(List *list) {
	assert(list!= NULL);
	if (list->size == 0) {
		printf("Error(peek_list): list is empty\n");
		return NULL;
	}
	return copy_data(list->head->data);
}

/**
 * ---------------------------------------------------------------------
 * Parameters: a pointer to a linked list (List*)
 * Returns: minimum data (Data*)
 * Description: returns copy of minimum data stored in list
 * if list is empty, prints error msg and returns NULL
 * Asserts: asserts given linked list is not Null
 * ---------------------------------------------------------------------
 */
Data* min_list(List *list) {
	assert(list!= NULL);
	if (list->size == 0) {
		printf("Error(min_list): list is empty\n");
		return NULL;
	}
	Data *min = list->head->data;
	Node *current = list->head;

	while (current != NULL) {
		if (compare_data(current->data, min) == 2) {
			min = current->data;
		}
		current = current->next;
	}
	return copy_data(min);
}

/**
 * ---------------------------------------------------------------------
 * Parameters: a pointer to a linked list (List*)
 * Returns: a pointer to a linked list (List*)
 * Description: returns copy of linked list
 * Asserts: asserts given linked list is not Null
 * ---------------------------------------------------------------------
 */
List* copy_list(List *list1) {
	assert(list1!= NULL);
	List *list2 = create_list();
	Node *current1 = list1->head;
	Node *current2 = NULL;
	list2->size = 0;

	while (current1 != NULL) {
		if (current2 != NULL) {
			current2->next = copy_node(current1);
			current2 = current2->next;
		} else {
			list2->head = copy_node(current1);
			current2 = list2->head;
		}
		current1 = current1->next;
		list2->size = list1->size;
	}

	return list2;

}

