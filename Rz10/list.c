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

List* create_list() {
	List *list = (List*) malloc(sizeof(List));
	list->head = NULL;
	list->size = 0;
	return list;
}
