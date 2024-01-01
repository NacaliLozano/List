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
	sort_List(self);
		printf("Current list: ");
		print_List(self);
		printf("Current size is %d\n", size(self));
}

int main() {
	List_t *foo = create_List();

	sort_and_print(foo);

	append(foo, 9999);
	sort_and_print(foo);

	append(foo, 0);
	sort_and_print(foo);

	append(foo, -9999);
	sort_and_print(foo);

	for (unsigned int i = 0; i < 997; i++) {
		srand(i);
		append(foo, rand());
	}
	sort_and_print(foo);


	return 0;

}
