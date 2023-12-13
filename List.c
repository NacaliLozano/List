#include <stdio.h>

typedef struct Node_t Node_t;
struct {
	int element;
	Node_t *next_node;
} Node_t;

typedef struct {
	unsigned int n_elements;
	Node_t *inner_list;
} List_t;

Node_t* create_Node(int element) {
	Node_t *self;

	self = (Node_t*)malloc(sizeof(Node_t));
	if (self == NULL) {
		return NULL;
	}
	self->element = element;
	self->next_node = NULL;

	return self;
}

void destroy_Node(Node_t* self) {
	free(self);
}

List_t create_List() {

	List_t self;

	self->n_elements = 0;
	self->inner_list = NULL;

	return self;
}

void destroy_List(List_t self) {
	unsigned int i;
	Node_t *temp, *current;

	current = self->inner_list;
	for (i = 0; i < self->n_elements; i++) {
		temp =  current->next_node;
		free(current);
		current = temp;
	}
	return;
}

void append(List_t self, int element) {
	unsigned int i;
	Node_t *current;

	current = self->inner_list;
	while (current->next_node != NULL) {
		current = current->next_node;
	}

	current->next_node = create_Node(element);
	self->n_elements++
}

int access_element(List_t self, unsigned int i) {
	unsigned int j;
	Node_t *current;

	current = self->inner_list;
	for (j = 0; j < i; j++) {
		if (current == NULL) {
			printf("Wrong input\n");
			return -1;
		}
		current = current->next_node;
	}
	return current->element;
}

int delete_element(List_t self, unsigned int i) {
	unsigned int j;
	Node_t *current, *previous;

	current = self->inner_list;
	previous = NULL;
	for (j = 0; j < i; j++) {
		if (current == NULL) {
			printf("Wrong input\n");
			return -1;
		}
		previous = current;
		current = current->next_node;
	}
	previous->next_node = current->next_node;
	destroy_Node(current);
	self->n_elements--;
	return 0;
}

unsigned int size(List_t self) {
	return self->n_elements;
}
