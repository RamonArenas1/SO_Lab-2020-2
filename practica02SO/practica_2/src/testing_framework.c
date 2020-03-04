/*
 * testing_framework.c
 *
 *  Created on: 11/02/2012
 *  Author: Alaín Chevanier
 */

#include <stdio.h>
#include <string.h>
#include "includes/list_node.h"
#include "includes/testing_framework.h"

// Variable to count successfully passed test
extern unsigned short test_passed;

/**
 * Asserts TRUE a given condition, and if condition is true then increments by
 * one the global variable 'test_passed'
 * @param condition
 * @return success
 */
int assert_true(int condition) {
    if (condition) {
        test_passed++;
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * Asserts FALSE a given condition, and if condition is false then increments by
 * one the global variable 'test_passed'
 * @param condition
 * @return success
 */
int assert_false(int condition) {
    return assert_true(!condition);
}

/**
 * Asserts NULL a given pointer, and if pointer is NULL then increments by
 * one the global variable 'test_passed'
 * @param pointer
 * @return success
 */
int assert_null(void *pointer) {
    return assert_true(pointer == NULL);
}

/**
 * Assert Equals the given arrays a1 and a2.
 */
int assert_equals_array(void *a1, void *a2, size_t num_bytes) {
    return assert_true(memcmp(a1, a2, num_bytes) == 0);
}


/**
 * Assert Equals the given lists l1 and l2.
 */
int assert_equals_list(struct list_node *l1, struct list_node *l2,
                       int (*compare)(const void *, const void *)) {
    unsigned int it = 0, rand1, rand2;

    struct list_node *head_e = l1, *head_t = l2;
    while (l1 != NULL && l2 != NULL) {
        if (l1->value != l2->value) {
            printf("Expected Value %d at position %d, but was %d\n", l1->value, it, l2->value);
            break;
        }
        rand1 = list_find_node(head_e, l1->rand);
        rand2 = list_find_node(head_t, l2->rand);
        if (rand1 != rand2) {
            printf("Random pointers are not equivalent at position %d, expected %d but was %d\n", it, rand1, rand2);
            break;
        }

        l1 = l1->next;
        l2 = l2->next;
        it++;
    }

    if (l1 == NULL && l2 != NULL) {
        puts("Received list is bigger than expected");
    }

    if (l1 != NULL && l2 == NULL) {
        puts("Received list is smaller than expected");
    }

    return assert_true(l1 == NULL && l2 == NULL);
}
