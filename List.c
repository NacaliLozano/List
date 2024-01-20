#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "List.h"




Node_t* create_Node(int element, Node_t *previous) {
	Node_t *self;

	self = (Node_t*)malloc(sizeof(Node_t));
	if (self != NULL) {
		self->element = element;
		self->next_node = NULL;
		self->previous_node = previous;
	}
	return self;
}

void destroy_Node(Node_t* self) {
	free(self); //If ptr is NULL, no operation is performed.
}

List_t* create_List() {

	List_t *self;

	self = (List_t*)malloc(sizeof(List_t));
	if (self != NULL) {
		self->n_elements = 0;
		self->first_node = NULL;
		self->last_node = NULL;
	}
	return self;
}

void destroy_List(List_t *self) {
	unsigned int i;
	Node_t *temp, *current;

	if (self != NULL) {
		current = self->first_node;
		for (i = 0; i < self->n_elements; i++) {
			assert(current != NULL);
			temp =  current->next_node;
			destroy_Node(current);
			current = temp;
		}
	}
	free(self);
}

int append(List_t *self, int element) {
	Node_t *temp;

	if (self == NULL) {
		return -1;
	}
	if (self->first_node == NULL) {
		self->first_node = create_Node(element, NULL);
		self->last_node = self->first_node;
	}
	else {
		temp = self->last_node;
		self->last_node = create_Node(element, temp);
		temp->next_node = self->last_node;
	}
	self->n_elements++;
	return 0;
}

int access_element(List_t *self, unsigned int i, int *element) {
	unsigned int j;
	Node_t *current;

	if (self == NULL || i >= self->n_elements) {
		return -1;
	}

	current = self->first_node;
	for (j = 0; j < i; j++) {
		assert(current != NULL);
		current = current->next_node;
	}
	*element = current->element;
	return 0;
}

int delete_element(List_t *self, unsigned int i) {
	unsigned int j;
	Node_t *current, *previous;

	if (self == NULL || i >= self->n_elements) {
		return -1;
	}

	current = self->first_node;
	if (i == 0) {
		self->first_node = current->next_node;
	}
	else if (i == self->n_elements - 1) {
		current = self->last_node;
		self->last_node->previous_node->next_node = NULL;
	}
	else {
		previous = NULL;
		for (j = 0; j < i; j++) {
			assert(current != NULL);
			previous = current;
			current = current->next_node;
		}
		previous->next_node = current->next_node;
		current->next_node->previous_node = previous;
	}
	destroy_Node(current);
	self->n_elements--;
	return 0;
}

int size(List_t *self, unsigned int *size) {
	if (self == NULL) {
		return -1;
	}
	*size = self->n_elements;
	return 0;
}

int sort_List(List_t *self) {
	Node_t *current, *next_node;
    int aux;
    unsigned int i, j;

    if (self == NULL) {
    	return -1;
    }

    //Cast to avoid an empty list to enter the loop
    for (i = 0; (int)i < (int)self->n_elements - 1; i++) {
    	current = self->first_node;
    	next_node = current->next_node;

        for (j = i + 1; j < self->n_elements; j++) {
            if (next_node == NULL) {
            	return -1;
            }

            if (current->element > next_node->element) {
                aux = current->element;
                current->element = next_node->element;
                next_node->element = aux;
            }
            current = next_node;
            next_node = next_node->next_node;
        }
    }
    return 0;
}

int print_List(List_t *self) {
	unsigned int j;
	Node_t *current;

	if (self == NULL) {
		return -1;
	}
	if (self->first_node == NULL) {
		printf("[]\n");
	}
	else {
		if (self->n_elements == 1) {
			printf("[%d]\n", self->first_node->element);
		}
		else {
			printf("[");
			current = self->first_node;
			for (j = 0; j < self->n_elements - 1; j++) {
				if (current == NULL) {
					return -1;
				}
				printf("%d, ", current->element);
				current = current->next_node;
			}
			printf("%d]\n", current->element);
		}
	}
	return 0;
}
