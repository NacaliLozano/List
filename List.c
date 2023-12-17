#include <stdio.h>
#include <stdlib.h>
#include "List.h"




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

List_t* create_List() {

	List_t *self;

	self = (List_t*)malloc(sizeof(List_t));
	if (self == NULL) {
		return NULL;
	}

	self->n_elements = 0;
	self->inner_list = NULL;

	return self;
}

void destroy_List(List_t *self) {
	unsigned int i;
	Node_t *temp, *current;

	current = self->inner_list;
	for (i = 0; i < self->n_elements; i++) {
		temp =  current->next_node;
		destroy_Node(current);
		current = temp;
	}
	free(self);
	return;
}

int append(List_t *self, int element) {
	Node_t *current;

	if (self == NULL) {
		return -1;
	}

	current = self->inner_list;
	if (current == NULL) {
		self->inner_list = create_Node(element);
		self->n_elements++;
		return 0;
	}
	while (current->next_node != NULL) {
		current = current->next_node;
	}

	current->next_node = create_Node(element);
	self->n_elements++;
	return 0;
}

int access_element(List_t *self, unsigned int i, int *element) {
	unsigned int j;
	Node_t *current;

	current = self->inner_list;
	for (j = 0; j < i; j++) {
		if (current == NULL) {
			return -1;
		}
		current = current->next_node;
	}
	*element = current->element;
	return 0;
}

int delete_element(List_t *self, unsigned int i) {
	unsigned int j;
	Node_t *current, *previous;

	current = self->inner_list;
	previous = NULL;
	for (j = 0; j < i; j++) {
		if (current == NULL) {
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

unsigned int size(List_t *self) {
	return self->n_elements;
}

int swap_nodes(List_t *self, unsigned int i, unsigned int j) {
	Node_t *current_i, *current_j, *previous_i, *previous_j, *aux;
	unsigned int index_i, index_j;
	
	if (i == j || i > self->n_elements || j > self->n_elements) {
		return -1;
	}
	
	if (i == 0) {
		current_j = self->inner_list;
		for (index_j = 0; index_j < j; index_j++) {
			if (current_j == NULL) {
				return -1;
			}
			previous_j = current_j;
			current_j = current_j->next_node;
		}
		aux = self->inner_list;

		self->inner_list = current_j;
		aux->next_node = current_j->next_node;
		current_j->next_node = aux->next_node;
		previous_j->next_node = aux;
		return 0;
	}
	else {
		if (j == 0) {
			current_i = self->inner_list;
			for (index_i = 0; index_i < i; index_i++) {
				if (current_i == NULL) {
					return -1;
				}
				previous_i = current_i;
				current_i = current_i->next_node;
			}
			aux = self->inner_list;
			previous_i->next_node = aux;
			self->inner_list = current_i;
			aux->next_node = current_i->next_node;
			current_i->next_node = aux->next_node;
			return 0;
		}
		else {
			current_i = self->inner_list;
			for (index_i = 0; index_i < i; index_i++) {
				if (current_i == NULL) {
					return -1;
				}
				previous_i = current_i;
				current_i = current_i->next_node;
			}

			current_j = self->inner_list;
			for (index_j = 0; index_j < j; index_j++) {
				if (current_j == NULL) {
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
	}
}

int sort_List(List_t *self) {
	unsigned int i, j;
	Node_t *current_i, *current_j;
	
	if (self == NULL) {
		return -3;
	}
	printf("Check 1\n");
	if (self->n_elements < 2) {
		return -1;
	}
	current_i = self->inner_list;
	printf("Check 2\n");
	for (i = 0; i < self->n_elements; i++) {
		current_j = current_i->next_node;
		printf("Check i%d\n", i);
		for (j = i + 1; j < self->n_elements; j++) {
			printf("Check j%d\n", j);
			if (current_i == NULL || current_j == NULL) {
				return -2;
			}
			else {
				if (current_j->element < current_i->element) {
					swap_nodes(self, i, j);
				}
			}
			current_j = current_j->next_node;
		}
		current_i = current_i->next_node;
	}
	return 0;
}

int print_List(List_t *self) {
	unsigned int j;
	Node_t *current;

	if (self == NULL) {
		printf("self == NULL");
		return -1;
	}
	else {
		if (self->inner_list == NULL) {
			printf("[]\n");
			return 0;
		}
		else {
			if (self->n_elements == 1) {
				printf("[%d]\n", self->inner_list->element);
			}
			else {
				printf("[");
				current = self->inner_list;
				for (j = 0; j < self->n_elements - 1; j++) {
					if (current == NULL) {
						printf("\nElement number %d is NULL\n", j);
						return -2;
					}
					printf("%d, ", current->element);
					current = current->next_node;
				}
				printf("%d]\n", current->element);
			}
		}
	}
	return 0;
}
