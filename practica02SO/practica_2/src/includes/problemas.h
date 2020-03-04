/*
 * problemas.h
 *
 *  Created on: 11/02/2012
 *      Author: Ricchy Alaín Pérez Chevanier
 */

#ifndef PROBLEMAS_H_
#define PROBLEMAS_H_

#include <stddef.h>
#include "list_node.h"

/*
 * This functions aims to create a copy of the original list where
 * the relationship between node given by the pointers rand is kept.
 * @param list - this is a pointer to the first element of the list
 */
struct list_node *list_create_copy(struct list_node *);

/*
 * Sort an array of any given data tipe by using the heap sort algorithm.
 * @param array - pointer to the first location in the array
 * @param length - number of elements that the array contains
 * @param data_size - size in bytes of each element that the array contains
 * @param compare - pointer to a function that compares to elements from the array
 */
void heap_sort(int *array, size_t length);


void list_insert_node(struct list_node **, struct list_node *);


int list_has_cycle(struct list_node *);


int anagrams(char *, char *);


long long *egypcian_multiplication(int, int);

long long calc_max_sum(int *, size_t);

#endif /* PROBLEMAS_H_ */
