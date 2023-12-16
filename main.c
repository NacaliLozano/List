/*
 * main.c
 *
 *  Created on: 15 dic 2023
 *      Author: nacali
 */



#include <stdio.h>
#include "List.h"

int main() {
	List_t *foo = NULL;

	foo = create_List();
	printf("Current list: ");
	print_List(foo);
	append(foo, 5);
	append(foo, 0);
	append(foo, -40);
	append(foo, 276);
	append(foo, 18);
	append(foo, -56);
	append(foo, 5);
	printf("Current list: ");
	print_List(foo);
	printf("%d\n", foo->n_elements);
	printf("sort_List error: %d\n", sort_List(foo));
	printf("Current list: ");
	print_List(foo);
	return 0;

}
