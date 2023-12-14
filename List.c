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

int swap_nodes(List_t self, unsigned int i, unsigned int j) {
	Node_t *current_i, *current_j, *previous_i, *previous_j, *aux;
	unsigned int index_i, index_j;
	
	if ( i == j || i > self->n-elements || j > self->n-elements) {
		printf("Wrong input\n");
		return -1;
	}
	
	current_i = self->inner_list;
	for (index_i = 0; index_i < i; index_i++) {
		if (current_i == NULL) {
			printf("Wrong input\n");
			return -1;
		}
		previous_i = current_i;
		current_i = current_i->next_node;
	}
	
	current_j = self->inner_list;
	for (index_j = 0; index_j < j; index_j++) {
		if (current_j == NULL) {
			printf("Wrong input\n");
			return -1;
		}
		previous_j = current_j;
		current_j = current_j->next_node;
	}
	
	previous_i->next_node = current_j;
	previous_j->next_node = current_i;
	aux = current_j->next_node;
	current_j->next_node = current_i->next_node;
	current_i->next_node = aux;
	return 0;
}

int sort_List(List_t self) {
	unsigned int i, j;
	
	if (self->n_elements < 2) {
		printf("Not enough elements to sort\n");
		return -1;
	}
	current_i = self->inner_list;
	for (i = 0; i < self->n_elements; i++) {
		current_j = current_i->next_node;
		for (j = i + 1; j < self->n_elements; j++) {
			if (current_i == NULL || current_j == NULL) {
				printf("Wrong input\n");
				return -2;
			}
			else {
				if (current_j->element < current_j->element) {
					swap_nodes(self, i, j);
				}
			}
			current_j = current_j->next_node;
		}
		current_i = current_i->next_node;
	}
}