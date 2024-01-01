#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "List.h"




Node_t* create_Node(int element) {
	Node_t *self;

	self = (Node_t*)malloc(sizeof(Node_t));
	if (self != NULL) {
		self->element = element;
		self->next_node = NULL;
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
		self->inner_list = NULL;
	}
	return self;
}

void destroy_List(List_t *self) {
	unsigned int i;
	Node_t *temp, *current;

	if (self != NULL) {
		current = self->inner_list;
		for (i = 0; i < self->n_elements; i++) {
			assert(current != NULL);
			temp =  current->next_node;
			destroy_Node(current);
			current = temp;
		}
	}
	free(self);
}

void append(List_t *self, int element) {
	Node_t *current;

	assert(self != NULL);
	current = self->inner_list;
	if (current == NULL) {
		self->inner_list = create_Node(element);
	}
	else {
		while (current->next_node != NULL) {
			current = current->next_node;
		}
		current->next_node = create_Node(element);
	}
	self->n_elements++;
}

int access_element(List_t *self, unsigned int i) {
	unsigned int j;
	Node_t *current;

	assert(self != NULL && i < self->n_elements);

	current = self->inner_list;
	for (j = 0; j < i; j++) {
		assert(current != NULL);
		current = current->next_node;
	}
	return current->element;
}

void delete_element(List_t *self, unsigned int i) {
	unsigned int j;
	Node_t *current, *previous;

	assert(self != NULL && i < self->n_elements);

	current = self->inner_list;
	if (i == 0) {
		self->inner_list = current->next_node;
	}
	else {
		previous = NULL;
		for (j = 0; j < i; j++) {
			assert(current != NULL);
			previous = current;
			current = current->next_node;
		}
		previous->next_node = current->next_node;
	}
	destroy_Node(current);
	self->n_elements--;
}

unsigned int size(List_t *self) {
	assert(self != NULL);
	return self->n_elements;
}

void swap_nodes(List_t *self, unsigned int i, unsigned int j) {
	Node_t *current_i, *current_j, *previous_i, *previous_j, *aux;
	unsigned int index_i, index_j;
	
    assert(self != NULL && i < self->n_elements && j < self->n_elements);

    current_i = self->inner_list;
    previous_i = NULL;
    for (index_i = 0; index_i < i; index_i++) {
        assert(current_i != NULL);
        previous_i = current_i;
        current_i = current_i->next_node;
    }

    current_j = self->inner_list;
    previous_j = NULL;
    for (index_j = 0; index_j < j; index_j++) {
        assert(current_j != NULL);
        previous_j = current_j;
        current_j = current_j->next_node;
    }

    if (previous_i != NULL) {
        previous_i->next_node = current_j;
    }
    else {
        self->inner_list = current_j;
    }

    if (previous_j != NULL) {
        previous_j->next_node = current_i;
    }
    else {
        self->inner_list = current_i;
    }

    aux = current_i->next_node;
    current_i->next_node = current_j->next_node;
    current_j->next_node = aux;

}

void sort_List(List_t *self) {
	Node_t *current, *next_node;
    int aux;
    unsigned int i, j;

    assert(self != NULL);

    //Cast to avoid an empty list to enter the loop
    for (i = 0; (int)i < (int)self->n_elements - 1; i++) {
    	current = self->inner_list;
    	next_node = current->next_node;

        for (j = i + 1; j < self->n_elements; j++) {
            assert(next_node != NULL);

            if (current->element > next_node->element) {
                aux = current->element;
                current->element = next_node->element;
                next_node->element = aux;
            }
            current = next_node;
            next_node = next_node->next_node;
        }
    }
}

void print_List(List_t *self) {
	unsigned int j;
	Node_t *current;

	assert(self != NULL);
	if (self->inner_list == NULL) {
		printf("[]\n");
	}
	else {
		if (self->n_elements == 1) {
			printf("[%d]\n", self->inner_list->element);
		}
		else {
			printf("[");
			current = self->inner_list;
			for (j = 0; j < self->n_elements - 1; j++) {
				assert(current != NULL);
				printf("%d, ", current->element);
				current = current->next_node;
			}
			printf("%d]\n", current->element);
		}
	}
}
