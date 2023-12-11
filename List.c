#include <stdio.h>
#include <stdarg.h>

typedef struct Node_t Node_t;
struct {
	int element;
	Node_t *next_node;
} Node_t;

typedef struct {
	unsigned int n_elements;
	Node_t *inner_list;
} List_t;

Node_t* create_Node(int element, Node_t* next_node) {
	Node_t* self;

	self = (Node_t*)malloc(sizeof(Node_t));
	if (self == NULL) {
		return NULL;
	}
	self->element = element;
	self->next_node = next_node;

	return self;
}

List_t create_List(int n, ...) {
    va_list args;
    va_start(args, n);
    unsigned int i;
	List_t list;

	list->n_elements = n;
    for (i = 0; i < n; i++) {

    }
}
