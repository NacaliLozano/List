/*
 * List.h
 *
 *  Created on: 15 dic 2023
 *      Author: nacali
 */

#ifndef LIST_H_
#define LIST_H_

struct Node_t {
	int element;
	struct Node_t *next_node;
};

typedef struct Node_t Node_t;

typedef struct {
	unsigned int n_elements;
	Node_t *inner_list;
} List_t;

Node_t* create_Node(int element);
void destroy_Node(Node_t* self);
List_t* create_List();
void destroy_List(List_t *self);
void append(List_t *self, int element);
int access_element(List_t *self, unsigned int i);
void delete_element(List_t *self, unsigned int i);
unsigned int size(List_t *self);
void swap_nodes(List_t *self, unsigned int i, unsigned int j);
void sort_List(List_t *self);
void print_List(List_t *self);

#endif /* LIST_H_ */
