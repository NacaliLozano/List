/*
 * main.c
 *
 *  Created on: 15 dic 2023
 *      Author: nacali
 */



#include <stdio.h>
#include <stdlib.h>
#include "List.h"

void sort_and_print(List_t *self) {
	unsigned int s;
	sort_List(self);
	printf("Current list: ");
	print_List(self);
	size(self, &s);
	printf("Current size is %u\n", s);
}

int main() {
	List_t *foo = NULL;
	int element;
	unsigned int s;

	destroy_List (foo);
	if (append(foo, 9999) == -1) {
		printf("append to NULL list behaved correctly\n");
	} else {
		printf("append to NULL list behaved incorrectly\n");
	}
	if (access_element(foo, 0, &element) == -1) {
		printf("access_element in a NULL list behaved correctly\n");
	} else {
		printf("access_element in a NULL list behaved incorrectly\n");
	}
	if (delete_element(foo, 0) == -1) {
		printf("delete_element in a NULL list behaved correctly\n");
	} else {
		printf("delete_element in a NULL list behaved incorrectly\n");
	}
	if (size(foo, &s) == -1) {
		printf("size of NULL list behaved correctly\n");
	} else {
		printf("size of NULL list behaved incorrectly\n");
	}
	if (swap_nodes(foo, 0, 1) == -1) {
		printf("swap_nodes in a NULL list behaved correctly\n");
	} else {
		printf("swap_nodes in a NULL list behaved incorrectly\n");
	}
	if (sort_List(foo) == -1) {
		printf("sort NULL list behaved correctly\n");
	} else {
		printf("sort NULL list behaved incorrectly\n");
	}
	if (print_List(foo) == -1) {
		printf("print NULL list behaved correctly\n");
	} else {
		printf("print NULL list behaved incorrectly\n");
	}

	foo = create_List();
	if (foo != NULL && foo->inner_list == NULL && foo->n_elements == 0) {
		printf("List creation successful\n");
	} else {
		printf("List creation failed\n");
	}
	if (access_element(foo, 0, &element) == -1) {
		printf("access_element in an empty list behaved correctly\n");
	} else {
		printf("access_element in an empty list behaved incorrectly\n");
	}
	if (delete_element(foo, 0) == -1) {
		printf("delete_element in an empty list behaved correctly\n");
	} else {
		printf("delete_element in an empty list behaved incorrectly\n");
	}
	if (swap_nodes(foo, 0, 1) == -1) {
		printf("swap_nodes in an empty list behaved correctly\n");
	} else {
		printf("swap_nodes in an empty list behaved incorrectly\n");
	}
	if (sort_List(foo) == 0) {
		printf("sorting an empty list behaved correctly\n");
	} else {
		printf("sorting an empty list behaved incorrectly\n");
	}
	sort_and_print(foo);


	append(foo, 9999);
	sort_and_print(foo);

	append(foo, 0);
	sort_and_print(foo);

	append(foo, -9999);
	sort_and_print(foo);

	for (int i = -500; i < 497; i++) {
		srand(i);
		append(foo, rand());
	}
	sort_and_print(foo);

	destroy_List(foo);

	return 0;

}
