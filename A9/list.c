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
# include "list.h"

Node* get_node(List *l, int indx);
int search(List *list, Data *d);
int is_equal_data(Data *d1, Data *d2);
/**
 * ------------------------------------------------------------
 * Parameters: 	d - a data item (Data*)
 * 				n - pointer to next node (Node*)
 * Returns: 	new node (Node*)
 * Description:	Creates a new node using the given data
 * Asserts:		data is not NULL
 * ------------------------------------------------------------
 */
Node* create_node(Data *d, Node *n) {
	assert(d);
	Node *node = (Node*) malloc(sizeof(Node));
	node->data = copy_data(d);
	node->next = n;
	return node;
}

/**
 * -------------------------------------------------------
 * Parameters: 	a node (Node*)
 * Returns: 	none
 * Description:	prints the contents of a node
 * 				invokes print_data
 * 				does not print next pointer
 * Assert:		n is not NULL
 * -------------------------------------------------------
 */
void print_node(Node *n) {
	assert(n);
	print_data(n->data);
	return;
}

/**
 * --------------------------------------------------------
 * Parameters: 	a node (Node*)
 * Returns: 	a copy node (Node*)
 * Description:	Creates a copy of the given node
 * 				The new copy has a copy version of the data
 * 				the next pointer points to the same node as the original node's next
 * Assert:		given node is not NULL
 * --------------------------------------------------------
 */
Node* copy_node(Node *n) {
	assert(n);
	return create_node(n->data, n->next);
}

/**
 * ---------------------------------------------------
 * Parameters:  a node (Node**)
 * Returns: 	none
 * Description:	destroys a node by:
 * 				- destroy the encompassed data
 * 				- setting next to NULL
 * 				- free the node pointer
 * Assert:		n and *n are not NULL
 * --------------------------------------------------
 */
void destroy_node(Node **n) {
	assert(n && *n);
//	destroy_data(&(*n)->data);
	(*n)->data = NULL;
	(*n)->next = NULL;
	free(*n);
	return;
}

//-----------------------------------------------------------
/**
 * Parameters: 	None
 * Returns: 	A pointer to linked list (List*)
 * Description:	Creates an empty linked list
 * 				head is set to NULL and size to 0
 * 				Returns a pointer to the newly created linked list
 * -----------------------------------------------------------
 */
List* create_list() {
	List *list = (List*) malloc(sizeof(List));
	list->head = NULL;
	list->size = 0;
	return list;
}

/**
 * -------------------------------------------------------------------
 * Parameters: 	Pointer to a linked list (List*)
 * Returns: 	None
 * Description:	traverse through all nodes
 * 				uses print_node(Node*) to print contents of nodes
 * 				starting from list head to tail
 * 				node1-->node2-->node3-->...-->NULL
 * 				prints <NULL> if empty list
 * Assert:		list is not NULL
 * -------------------------------------------------------------------
 */
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

/**
 * ---------------------------------------------------------------
 * Parameters: 	A linked list (List*)
 * 				A data item (Data*)
 * Returns: 	None
 * Description:	appends the given data item to the tail of the linked list
 * 				updates size and may update head
 * Assert		list and d are not NULL
 * ---------------------------------------------------
 */
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
 * ---------------------------------------------------------------
 * Parameters: 	a linked list (List**)
 * Returns: 	None
 * Description:	Destroys a given linked list
 * 				Deletes all nodes (which takes care of destroying data)
 * 				set head to NULL and size to 0
 * 				free list pointer
 * Assert:		**list and *list are is not Null
 * ---------------------------------------------------------------
 */
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

//------------------------- Assignment -------------------------
/**
 * -------------------------------------------------------------------------
 * Parameters: 	a linked list (List*)
 * 				a data item (Data*)
 * 				an index (int)
 * Returns: 	True/False
 * Description:	Inserts the given data item at position (index) at the linked list
 * 				if given index is out of range --> print an error and return False
 * 				returns True if insertion is successful, False otherwise
 * Assert:		given array and data pointers are not Null
 * -------------------------------------------------------------------------
 */
int insert_list(List *list, Data *d, int index) {
	assert(list!= NULL && d !=NULL);
	//error checking
	if (index < 0 || (index > list->size && list->size != 0)) {
		printf("Error(insert_list): index out of range\n");
		return False;
	}

	if (list->head == NULL) {						//inserting into empty list
		Node *new = create_node(d, NULL);
		list->head = new;

	} else if (index == 0) {						//inserting at head
		Node *new = create_node(d, list->head);
		list->head = new;

	} else if (list->size - 1 == index) {		//inserting before last element
		Node *insertion = get_node(list, index);
		Node *new = create_node(d, insertion->next);
		insertion->next = new;

	} else if (list->size == index) {				//appending
		append_list(list, d);
		list->size--;		//had to decrement because I will increment later on
	} else {										//all other cases
		Node *insertion = get_node(list, index);
		Node *new = create_node(d, insertion->next);
		insertion->next = new;
	}
	list->size++;

	return True;
}

/**
 * -----------------------------------------------------------------
 * Parameters: 	list - a linked list (List*)
 * 				i - an index (int)
 * Returns: 	Copy of popped data (Data*)
 * Description:	deletes the node at position (index) at the linked list
 * 				A copy of the data in the removed node is returned.
 * 				if given index is out of range --> print an error and return NULL
 * 				if given linked list is empty --> print an error and return NULL
 * Asserts:		given linked list is not NULL
 * ------------------------------------------------------------------
 */
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

/**
 * ---------------------------------------------------------------------
 * Parameters: 	a linked List (List*)
 * 				start index (int)
 * 				end index  (int)
 * Returns: 	None
 * Description:	deletes items from the list from index start to end (inclusive both ends)
 * 				Updates head and size as necessary
 * 				if given list is empty, print error and return
 *				if given start or end indices are out of range --> print error msg and return
 * Assert:		linked list is not NULL
 * ---------------------------------------------------------------------
 */
void cut_list(List *list, int start, int end) {
	assert(list!=NULL);
	//error checking
	if (list->size == 0) {
		printf("Error(cut_list): Linked List is empty\n");
		return;
	}
	if (start < 0 || start >= list->size) {
		printf("Error(cut_list): Invalid start index\n");
		return;
	}
	if (end < 0 || end >= list->size || end < start) {
		printf("Error(cut_list): Invalid end index\n");
		return;
	}
	Node *remove; //create temp for use later

	if ((end - start + 1) == list->size) { //case where we're removing entire list
		remove = list->head;
		list->head = NULL;
		list->size = 0;
	} else {										//all other cases
		Node *a = get_node(list, start); //'a' represents the node before start
		Node *z = get_node(list, end + 2); //'z' represents the node after end

		if (start == end) {							//removing a single node
			remove = a->next;
			a->next = a->next->next;
			remove->next = NULL;

		} else {									//removing multiple nodes
			remove = a->next;
			Node *temp = remove;
			for (int i = 0; i < (end - start); i++) {
				temp = temp->next;
			}
			temp->next = NULL;
			a->next = z;

		}
		list->size = list->size - (end - start + 1);	//update size

		if (start == 0) {	//update head if it was removed
			list->head = a;
		}
	}

	//destroy the removed nodes
	List *junk = create_list();
	junk->head = remove;
	destroy_list(&junk);
	return;
}

/**
 * ---------------------------------------------------------------------
 * Parameters: 	a linked list (List*)
 * 				start index (int)
 * 				end index  (int)
 * Returns: 	a linkedList (List*)
 * Description:	Constructs and returns a new linked list.
 * 				The new list contains elements from start to end (inclusive both ends)
 * 				if list is empty, print error msg and return empty list
 * 				if start/end is out of scope, print error msg and return empty list
 * 				Check if end index is greater than or requal to start index
 * Asserts:		list is not NULL
 * ---------------------------------------------------------------------
 */
List* sub_list(List *list, int start, int end) {
	assert(list != NULL);
	//error checking
	if (list->head == NULL) {
		printf("Error(sub_list): Linked list is empty\n");
		return create_list();
	}
	if (start < 0 || start >= list->size) {
		printf("Error(sub_list): Invalid start index\n");
		return create_list();
	}
	if (end < 0 || end >= list->size || end < start) {
		printf("Error(sub_list): Invalid end index\n");
		return create_list();
	}
	List *linkedList = create_list();
	if (start == end) { //single item list
		Node *new_head = copy_node(get_node(list, start + 1));
		linkedList->head = new_head;
		linkedList->size = 1;
		linkedList->head->next = NULL;
	} else {

		Node *new_head = copy_node(get_node(list, start + 1));
		linkedList->head = new_head;
		linkedList->size = end - start + 1;
		Node *current = linkedList->head;
		for (int i = 0; i < (end - start); i++) {
			current->next = copy_node(current->next);
			current = current->next;
		}
		current->next = NULL;
	}
	return linkedList;
}

/**
 * ---------------------------------------------------------------------
 * Parameters: 	a pointer to a linked list (List*)
 * 				i - index of first item (int)
 * 				j - index of second item (int)
 * Returns: 	None
 * Description:	swaps items i and j in the list
 * 				if invalid i and j, print error msg and return
 * Asserts:		asserts given linked list is not Null
 * ---------------------------------------------------------------------
 */
void swap_list(List *list, int i, int j) {
	assert(list != NULL);
	if (list->size == 0) {
		printf("Error(swap_list): list is empty\n");
		return;
	}

	if (i < 0 || j < 0 || i >= list->size || j >= list->size) {
		printf("Error (swap_list): Invalid value of i or j\n");
		return;
	}

	if (i == j) { //can't swap item with itself
		return;
	}

	//create nodes that precede i and j
	Node *prev1 = NULL;
	Node *prev2 = NULL;

	if (i != 0)
		prev1 = get_node(list, i);
	if (j != 0)
		prev2 = get_node(list, j);

	//create the nodes that will be swapped
	Node *node1 = NULL;
	Node *node2 = NULL;
	if (i == 0)
		node1 = list->head;
	else
		node1 = prev1->next;

	if (j == 0)
		node2 = list->head;
	else
		node2 = prev2->next;

	//create a temp node to hold a node while swapping
	Node *temp = NULL;

	//connect prev1 to node2
	if (prev1 != NULL)
		prev1->next = node2;

	//connect prev2 to node1
	if (prev2 != NULL)
		prev2->next = node1;

	//swap the next nodes of both node1 and node2
	temp = node1->next;
	node1->next = node2->next;
	node2->next = temp;

	//update head if any of the swapped nodes was the head
	if (i == 0)
		list->head = node2;
	else if (j == 0)
		list->head = node1;

	return;
}

/**
 * ---------------------------------------------------------------------
 * Parameters: 	first linked list (List*)
 * 				second linked list (List*)
 * Returns: 	new list (List*)
 * Description:	Creates a new list that contains items which appear in both lists
 * 				No duplicates allowed
 * Assert:		both linked lists are not NULL
 * ---------------------------------------------------------------------
 */
List* intersection_list(List *list1, List *list2) {
	assert(list1 != NULL && list2!= NULL);

	Node *current = list1->head;
	List *list3 = create_list();

	while (current != NULL) {

		if (search(list2, current->data) >= 0) {
			if (search(list3, current->data) == -1) {
				append_list(list3, copy_data(current->data));
			}
		}
		current = current->next;

	}
	return list3;
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

int search(List *list, Data *d) {
	//looks for data in given list
	Node *current = list->head;
	int index = -1, counter = 0;
	while (current != NULL) {
		if (is_equal_data(current->data, d) == 1) {
			index = counter;
			break;
		}
		counter++;
		current = current->next;
	}
	return index;
}

int is_equal_data(Data *d1, Data *d2) {
	//checks whether two data objects are equal
	if (d1->time == d2->time && d1->arrival == d2->arrival
			&& d1->PID == d2->PID)
		return 1;
	else
		return 0;
}
