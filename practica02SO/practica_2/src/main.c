/*
 * main.c
 *
 *  Author: Alaín CHevanier
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "includes/problemas.h"
#include "includes/booleans.h"
#include "includes/list_node.h"
#include "includes/testing_framework.h"

#define TOTAL_TEST        46
#define PASS            "PASS"
#define FAIL            "FAIL"

#define ABS(x) ((x) < 0 ? -(x) : (x))

// Variable to count successfully passed test
extern unsigned short test_passed;

void test_hc_empty() {
    struct list_node *list;

    list = NULL;
    printf("Empty list: %s\n", assert_false(list_has_cycle(list)) ? PASS : FAIL);
}

void test_hc_single_node_no_cycle() {
    struct list_node *list;

    list = NULL;
    create_random_list(&list, 1);
    printf("Single node, no cycle: %s\n", assert_false(list_has_cycle(list)) ? PASS : FAIL);
    free(list);
}

void test_hc_single_node_cycle() {
    struct list_node *list;

    list = NULL;
    create_random_list(&list, 1);
    list->next = list;
    printf("Single node, cycle: %s\n", assert_true(list_has_cycle(list)) ? PASS : FAIL);
    free(list);
}

void test_hc_list_no_cycle() {
    int size;
    struct list_node *list;

    size = 10000 + (rand() % 10000);
    list = NULL;
    create_random_list(&list, size);
    printf("Huge list, no  cycle: %s\n", assert_false(list_has_cycle(list)) ? PASS : FAIL);
    free_list(list);
}

void test_hc_list_cycle() {
    int size, index, i;
    struct list_node *list, *choice, *last;
    struct list_node *it;

    list = choice = last = NULL;
    size = 10000 + (rand() % 10000);
    index = rand() % size;

    create_random_list(&list, size);
    for (it = list, i = 0; it != NULL; it = it->next, i++) {
        if (index == i) {
            choice = it;
        }

        if (it->next == NULL) {
            last = it;
        }
    }
    last->next = choice;
    printf("Huge list, cycle: %s\n", assert_true(list_has_cycle(list)) ? PASS : FAIL);
    last->next = NULL;
    free_list(list);
}

/**
 * Test for list_has_cycle function
 */
void test_list_has_cycle() {
    puts("TESTS FOR HAS_CYCLE FUNCTION");
    test_hc_empty();
    test_hc_single_node_no_cycle();
    test_hc_single_node_cycle();
    test_hc_list_no_cycle();
    test_hc_list_cycle();
    puts("");
}

///////////////////////////////////////////////////////////////////////////////////////////////

void test_in_empty_and_empty() {
    struct list_node *list;

    list = NULL;
    list_insert_node(&list, NULL);
    printf("Empty list, empty new_node: %s\n", assert_null(list) ? PASS : FAIL);
}

void test_in_empty_and_single_node() {
    int x;
    struct list_node *list;
    struct list_node *new_node;

    new_node = list = NULL;
    create_random_list(&new_node, 1);
    x = new_node->value;
    list_insert_node(&list, new_node);

    printf("Empty list, single new_node: %s\n",
           assert_true(list == new_node && list->next == NULL && list->value == x) ? PASS : FAIL);

    free(new_node);
}

void test_in_empty_and_list() {
    struct list_node *list;
    struct list_node *new_node;
    struct list_node *tmp;

    tmp = new_node = list = NULL;
    create_random_list(&new_node, 2);
    create_random_list(&tmp, 1);
    tmp->value = new_node->value;

    list_insert_node(&list, new_node);
    printf("Empty list, multi-node list: %s\n",
           assert_equals_list(tmp, list) && list_find_node(list, new_node) != -1 ? PASS : FAIL);
    free_list(new_node);
    free_list(tmp);
}

void test_in_list_and_empty() {
    struct list_node *list, *tmp, *it1, *it2;
    int size;

    size = 1 + (rand() % 10);

    list = tmp = NULL;
    create_random_list(&list, size);
    create_random_list(&tmp, size);

    for (it1 = list, it2 = tmp; it1 != NULL; it2->value = it1->value,
                                             it1 = it1->next, it2 = it2->next);
    list_insert_node(&list, NULL);
    printf("List, empty list: %s\n",
           assert_equals_list(tmp, list) ? PASS : FAIL);
    free_list(list);
    free_list(tmp);
}

int compare(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

void test_in_list_and_single_node() {
    struct list_node *list, *tmp, *node, *it, *it2;
    int size, cur_val, i;
    int *values;

    size = 100 + (rand() % 900);

    list = node = tmp = NULL;
    create_random_list(&list, size - 1);
    create_random_list(&node, 1);
    create_random_list(&tmp, size);

    values = (int *) malloc(sizeof(int) * (size + 1));
    if (values == NULL) {
        exit(-1);
    }

    cur_val = rand() % 100;
    for (it = list, i = 0; it != NULL; i++, cur_val += 2 + rand() % 100, it = it->next) {
        it->value = cur_val;
        values[i] = cur_val;
    }

    values[i] = rand() % 10000;
    node->value = values[i];

    qsort(values, size, sizeof(int), compare);
    for (i = 0, it2 = tmp; i < size; i++, it2 = it2->next) {
        it2->value = values[i];
    }

    list_insert_node(&list, node);

    printf("List, single-node list, result contains new_node: %s\n",
           assert_true(list_find_node(list, node) != -1) ? PASS : FAIL);
    printf("List, single-node list: %s\n",
           assert_equals_list(tmp, list) && list_find_node(list, node) != -1 ? PASS : FAIL);

    free_list(list);
    free_list(tmp);
    free(values);
}

void test_in_list_and_list() {
    struct list_node *list, *tmp, *node, *it, *it2;
    int size, cur_val, i;
    int *values;

    size = 100 + (rand() % 900);

    list = node = tmp = NULL;
    create_random_list(&list, size - 1);
    create_random_list(&node, 2);
    create_random_list(&tmp, size);

    values = (int *) malloc(sizeof(int) * (size + 1));
    if (values == NULL) {
        exit(-1);
    }

    cur_val = rand() % 100;
    for (it = list, i = 0; it != NULL; i++, it = it->next, cur_val += 2 + rand() % 100) {
        it->value = cur_val;
        values[i] = cur_val;
    }

    values[i] = rand() % 10000;
    node->value = values[i];

    qsort(values, size, sizeof(int), compare);
    for (i = 0, it2 = tmp; i < size; i++, it2 = it2->next) {
        it2->value = values[i];
    }

    list_insert_node(&list, node);

    printf("List, multi-node list: %s\n",
           assert_equals_list(tmp, list) && list_find_node(list, node) != -1 ? PASS : FAIL);

    free_list(list);
    free_list(tmp);
    free(values);
}

void test_in_list_and_single_node_first() {
    struct list_node *list, *tmp, *node, *it, *it2;
    int size, cur_val, i;
    int *values;

    size = 100 + (rand() % 900);
    list = node = tmp = NULL;
    create_random_list(&list, size - 1);
    create_random_list(&node, 1);
    create_random_list(&tmp, size);

    values = (int *) malloc(sizeof(int) * (size + 1));
    if (values == NULL) {
        exit(-1);
    }

    cur_val = rand() % 100;
    for (it = list, i = 0; it != NULL; i++, it = it->next, cur_val += 2 + rand() % 100) {
        it->value = cur_val;
        values[i] = cur_val;
    }

    values[i] = get_minimum(list) - 1;
    node->value = values[i];

    qsort(values, size, sizeof(int), compare);
    for (i = 0, it2 = tmp; i < size; i++, it2 = it2->next) {
        it2->value = values[i];
    }

    list_insert_node(&list, node);

    printf("List, single-node list, first: %s\n",
           assert_equals_list(tmp, list) && list_find_node(list, node) != -1 ? PASS : FAIL);

    free_list(list);
    free_list(tmp);
    free(values);
}

void test_in_list_and_single_node_last() {
    struct list_node *list, *tmp, *node, *it, *it2;
    int size, cur_val, i;
    int *values;

    size = 100 + (rand() % 900);
    list = node = tmp = NULL;
    create_random_list(&list, size - 1);
    create_random_list(&node, 1);
    create_random_list(&tmp, size);

    values = (int *) malloc(sizeof(int) * (size + 1));
    if (values == NULL) {
        exit(-1);
    }

    cur_val = rand() % 100;
    for (it = list, i = 0; it != NULL; it = it->next, i++, cur_val += 2 + rand() % 100) {
        it->value = cur_val;
        values[i] = cur_val;
    }

    values[i] = get_maximum(list) + 1;
    node->value = values[i];

    qsort(values, size, sizeof(int), compare);
    for (i = 0, it2 = tmp; i < size; i++, it2 = it2->next) {
        it2->value = values[i];
    }

    list_insert_node(&list, node);

    printf("List, single-node list, last: %s\n",
           assert_equals_list(tmp, list) && list_find_node(list, node) != -1 ? PASS : FAIL);

    free_list(list);
    free_list(tmp);
    free(values);
}

void test_in_list_and_list_first() {
    struct list_node *list, *tmp, *node, *it, *it2;
    int size, cur_val, i;
    int *values;

    size = 100 + (rand() % 900);
    list = node = tmp = NULL;
    create_random_list(&list, size - 1);
    create_random_list(&node, 2);
    create_random_list(&tmp, size);

    values = (int *) malloc(sizeof(int) * (size + 1));
    if (values == NULL) {
        exit(-1);
    }

    cur_val = rand() % 100;
    for (it = list, i = 0; it != NULL; i++, it = it->next, cur_val += 2 + rand() % 100) {
        it->value = cur_val;
        values[i] = cur_val;
    }

    values[i] = get_minimum(list) - (rand() % 100);
    node->value = values[i];

    qsort(values, size, sizeof(int), compare);
    for (i = 0, it2 = tmp; i < size; i++, it2 = it2->next) {
        it2->value = values[i];
    }

    list_insert_node(&list, node);

    printf("List, multi-node list, first: %s\n",
           assert_equals_list(tmp, list) && list_find_node(list, node) != -1 ? PASS : FAIL);

    free_list(list);
    free_list(tmp);
    free(values);
}

void test_in_list_and_list_last() {
    struct list_node *list, *tmp, *node, *it, *it2;
    int size, cur_val, i;
    int *values;

    size = 100 + (rand() % 900);
    list = node = tmp = NULL;
    create_random_list(&list, size - 1);
    create_random_list(&node, 2);
    create_random_list(&tmp, size);

    values = (int *) malloc(sizeof(int) * (size + 1));
    if (values == NULL) {
        exit(-1);
    }

    cur_val = rand() % 100;
    for (it = list, i = 0; it != NULL; i++, it = it->next, cur_val += 2 + rand() % 100) {
        it->value = cur_val;
        values[i] = cur_val;
    }

    values[i] = get_maximum(list) + 1;
    node->value = values[i];

    qsort(values, size, sizeof(int), compare);
    for (i = 0, it2 = tmp; i < size; i++, it2 = it2->next) {
        it2->value = values[i];
    }

    list_insert_node(&list, node);

    printf("List, multi-node list, last: %s\n",
           assert_equals_list(tmp, list) && list_find_node(list, node) != -1 ? PASS : FAIL);

    free_list(list);
    free_list(tmp);
    free(values);
}

/**
 * Test for insert node
 */
void test_list_insert_node() {
    puts("TESTS FOR INSERT_NODE FUNCTION");

    test_in_empty_and_empty();
    test_in_empty_and_single_node();
    test_in_empty_and_list();
    test_in_list_and_empty();
    test_in_list_and_single_node();
    test_in_list_and_list();
    test_in_list_and_single_node_first();
    test_in_list_and_list_first();
    test_in_list_and_single_node_last();
    test_in_list_and_list_last();

    puts("");
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void test_a_null_and_null() {
    char *s1, *s2;
    s1 = s2 = NULL;
    printf("Null Strings: %s\n", assert_false(anagrams(s1, s2)) ? PASS : FAIL);
}

void test_a_empty_and_empty() {
    char s1[] = "", s2[] = "";
    printf("Empty Strings: %s\n", assert_true(anagrams(s1, s2)) ? PASS : FAIL);
}

void test_a_empty_and_string() {
    char s1[] = "", s2[] = "hola";
    printf("Empty Strings, String: %s\n", assert_false(anagrams(s1, s2)) ? PASS : FAIL);
}

void test_a_string_and_empty() {
    char s1[] = "hola", s2[] = "";
    printf("String, Empty Strings: %s\n", assert_false(anagrams(s1, s2)) ? PASS : FAIL);
}

void test_a_string_and_string_false() {
    char s1[] = "no me la se", s2[] = "si me la se";
    printf("No anagrams: %s\n", assert_false(anagrams(s1, s2)) ? PASS : FAIL);
}

void test_a_string_and_string_true() {
    char s1[] = "limala asno", s2[] = "la monalisa";
    printf("Anagrams: %s\n", assert_true(anagrams(s1, s2)) ? PASS : FAIL);
}

#define SIZE_TEST    10000

void test_big_strings_true() {
    char s1[SIZE_TEST];
    char s2[SIZE_TEST];
    int i, length;

    struct list_node *list = NULL;
    struct list_node *tmp;

    length = SIZE_TEST - 1;
    create_random_list(&list, length);

    for (i = 0, tmp = list; i < length; i++, tmp = tmp->next) {
        s1[i] = tmp->value = ABS(60 + (tmp->value % 68));
    }
    s1[i] = '\0';

    for (i = 0; length > 0; length--, i++) {
        int index = rand() % length;
        short int val = remove_at(index, &list);

        s2[i] = val;
    }
    s2[i] = '\0';


    printf("Big anagrams: %s\n", assert_true(anagrams(s1, s2)) ? PASS : FAIL);
}

void test_big_strings_false() {
    char s1[10000];
    char s2[10000];

    int i, p;

    s1[0] = rand() % 128;
    s2[0] = 128 - s1[0] - 1;

    for (i = 1; i < 10000; i++) {
        s1[i] = rand() % 128;
        p = rand() % 100;
        s2[i] = (p < 7) ? rand() % 128 : s1[i];
    }

    printf("Big strings, no anagrams: %s\n", assert_false(anagrams(s1, s2)) ? PASS : FAIL);
}

static void test_strings_with_different_ints() {
    char s1[] = "ac";
    char s2[] = "bb";
    printf("Same weigth, different strings: %s\n", assert_false(anagrams(s1, s2)) ? PASS : FAIL);
}

static void test_contain_same_chars_no_anagrams() {
    char s1[] = "ccaaca";
    char s2[] = "aacaca";
    printf("Same characters, different strings: %s\n", assert_false(anagrams(s1, s2)) ? PASS : FAIL);
}

/**
 * Test for are_they_anagrams?
 */
void test_anagrams() {
    puts("TESTS FOR ANAGRAMS FUNCTION");

    test_a_null_and_null();
    test_a_empty_and_empty();
    test_a_empty_and_string();
    test_a_string_and_empty();
    test_a_string_and_string_false();
    test_a_string_and_string_true();

    /**
     * Additional functions testing anagrams heavely.
     */
    test_big_strings_true();
    test_big_strings_false();
    test_strings_with_different_ints();
    test_contain_same_chars_no_anagrams();

    puts("");
}

//////////////////////////////////////////////////////////////////////////////////////
/*
static void print_int_array (int* array, size_t length) {
  printf ("[");
  while (length--) {
    printf ("%d, ", *array++);
  }
  printf ("]\n");
  }*/

/* Pruebas Unitarias para la multiplicación Egipcia */
void test_zero() {
    printf("Multiplication by zero left: %s\n", assert_null(egypcian_multiplication(0, 1)) ? PASS : FAIL);
    printf("Multiplication by zero rigth: %s\n", assert_null(egypcian_multiplication(1, 0)) ? PASS : FAIL);
}

void test_functional() {
    long long expected[] = {5, 238, 952, 1904, 3094};
    long long *result = egypcian_multiplication(13, 238);

    //print_int_array (expected, 5);
    //print_int_array (result, 5);

    printf("Mutiplication functional test case: %s\n",
           result != NULL && assert_equals_array(expected, result, expected[0] * sizeof(int)) ? PASS : FAIL);
}

void test_robustness() {
    int _n, _m;
    _n = _m = 1000000000;

    long long expected[] = {15ll, 512000000000ll, 2048000000000ll,
                            16384000000000ll, 32768000000000ll, 131072000000000ll,
                            524288000000000ll, 1048576000000000ll, 8388608000000000ll,
                            16777216000000000ll, 33554432000000000ll, 134217728000000000ll,
                            268435456000000000ll, 536870912000000000ll, 1000000000000000000ll};

    long long *result = egypcian_multiplication(_n, _m);

    printf("Mutiplication robustness test case: %s\n",
           result != NULL && assert_equals_array(expected, result, expected[0] * sizeof(int)) ? PASS : FAIL);
}

void test_egypcian_multiplication() {
    puts("TESTS FOR EGYPCIAN MULTIPLICATION:");
    test_zero();
    test_functional();
    test_robustness();
    puts("");
}

/////////////////////////////////////////////////////////////////

static void test_heapsort_single_elem() {
    int array[] = {12};
    int expected[] = {12};
    size_t size = 1;

    heap_sort(array, size);
    printf("Single element array: %s\n",
           assert_equals_array(expected, array, size * sizeof(int)) ? PASS : FAIL);
}

static void test_heapsort_complete() {
    int array[] = {7, 5, 1, 12, -6, 2, 11};
    int expected[] = {-6, 1, 2, 5, 7, 11, 12};
    size_t size = 7;

    heap_sort(array, size);

    //print_int_array (expected, size);
    //print_int_array (array, size);

    printf("Complete Tree: %s\n",
           assert_equals_array(expected, array, size * sizeof(int)) ? PASS : FAIL);
}

static void test_heapsort_incomplete() {
    int array[] = {7, 5, 1, 12, -6, 2, 11, 3};
    int expected[] = {-6, 1, 2, 3, 5, 7, 11, 12};
    size_t size = 8;

    heap_sort(array, size);

    //print_int_array (expected, size);
    //print_int_array (array, size);

    printf("Incomplete Tree: %s\n",
           assert_equals_array(expected, array, size * sizeof(int)) ? PASS : FAIL);
}

static void test_heapsort_worstcase() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    size_t size = 12;

    heap_sort(array, size);
    printf("Worst case runtime: %s\n",
           assert_equals_array(expected, array, size * sizeof(int)) ? PASS : FAIL);
}

static void test_heapsort_easycase() {
    int array[] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    size_t size = 12;

    heap_sort(array, size);
    printf("Linear Execution: %s\n",
           assert_equals_array(expected, array, size * sizeof(int)) ? PASS : FAIL);
}

static void test_heapsort_repetition() {
    int array[] = {7, 3, 1, 12, 2, 2, 11, 3};
    int expected[] = {1, 2, 2, 3, 3, 7, 11, 12};
    size_t size = 8;

    heap_sort(array, size);
    printf("With Repetitions: %s\n",
           assert_equals_array(expected, array, size * sizeof(int)) ? PASS : FAIL);
}

static int int_compare(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

static void test_heapsort_huge_input() {
    size_t size = (10000 + rand()) % 100000;

    int *array;
    int *expected;
    array = (int *) malloc(sizeof(int) * size);
    expected = (int *) malloc(sizeof(int) * size);

    size_t i = 0;
    for (; i < size; i++) {
        array[i] = expected[i] = rand() % 10000;
    }

    qsort(expected, size, sizeof(int), int_compare);
    heap_sort(array, size);
    printf("Huge array: %s\n",
           assert_equals_array(expected, array, size * sizeof(int)) ? PASS : FAIL);
    free(expected);
    free(array);
}

void test_heap_sort() {
    puts("TESTS FOR HEAP SORT:");
    test_heapsort_single_elem();
    test_heapsort_complete();
    test_heapsort_incomplete();
    test_heapsort_worstcase();
    test_heapsort_easycase();
    test_heapsort_repetition();
    test_heapsort_huge_input();
    puts("");
}

static void test_create_copy_empty_list() {
    struct list_node *expected = NULL;
    struct list_node *result = NULL;
    printf("Empty List: %s\n",
           assert_equals_list(expected, result) ? PASS : FAIL);
}

static void test_create_copy_single_node() {
    struct list_node *expected;
    create_random_list_with_rand(&expected, 1, TRUE);

    struct list_node *result = list_create_copy(expected);
    printf("Single node: %s\n",
           assert_equals_list(expected, result) ? PASS : FAIL);

    free_list(expected);
    free_list(result);
}

static void test_create_copy_huge_list() {
    struct list_node *expected;
    size_t size = 10000;
    create_random_list_with_rand(&expected, size, TRUE);

    struct list_node *result = list_create_copy(expected);
    printf("Huge list: %s\n",
           assert_equals_list(expected, result) ? PASS : FAIL);

    free_list(expected);
    free_list(result);
}

/*
static int ref_ind(struct list_node* list, struct list_node* node) {
  if (node == NULL) {
    return -1;
  }
  
  int i=0;
  while (list != NULL) {
    if (list == node) {
      return i;
    }
    list = list->next;
    i++;
  }
  
  return -1;
  }*/

static void test_counter_example() {
    struct list_node n1, n2, n3, n4;
    n1.value = 1;
    n2.value = 1;
    n3.value = 3;
    n4.value = 4;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = NULL;
    n1.rand = &n4;
    n2.rand = &n1;
    n3.rand = &n3;
    n4.rand = &n3;

    struct list_node *result = list_create_copy(&n1);

    /*
    struct list_node *tmp1 = &n1, *tmp2 = result;
    while (tmp1 != NULL) {
      printf ("ind_org = %d; ind_cpy = %d\n", ref_ind(&n1, tmp1->rand), ref_ind(result, tmp2->rand));
      tmp1 = tmp1->next;
      tmp2 = tmp2->next;
    }
    */

    printf("counter example: %s\n",
           assert_equals_list(&n1, result) ? PASS : FAIL);
}

void test_create_copy() {
    puts("TESTS FOR LIST_CREATE_COPY:");
    test_create_copy_empty_list();
    test_create_copy_single_node();
    test_create_copy_huge_list();
    test_counter_example();
    puts("");
}

/**
 * Pruebas para suma máxima
 */

static
void test_ms_functional() {
    long long expected = 6ll;
    int array[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    printf("Functional test: %s\n",
           assert_true(expected == calc_max_sum(array, 9)) ? PASS : FAIL);
}

static inline
long long max(long long a, long long b) {
    return a > b ? a : b;
}

static
void test_ms_negative_sum() {
    long long expected = -100000ll, tmp;
    int array[100];
    size_t length = 100, i = 0;
    while (i < length) {
        tmp = (rand() % 100000) * -1;
        expected = max(expected, tmp);
        array[i++] = tmp;
    }

    printf("Negative sum: %s\n",
           assert_true(expected == calc_max_sum(array, 100)) ? PASS : FAIL);
}

static
void test_ms_all_positive() {
    long long expected = 0, tmp;
    int array[100];
    size_t length = 100, i = 0;
    while (i < length) {
        tmp = rand() % 100000;
        expected += tmp;
        array[i++] = tmp;
    }

    printf("All Positive sum: %s\n",
           assert_true(expected == calc_max_sum(array, 100)) ? PASS : FAIL);
}

static
void test_ms_zero_elements() {
    long long expected = 0ll;
    int array[0];
    size_t length = 0;

    printf("No elements sum: %s\n",
           assert_true(expected == calc_max_sum(array, length)) ? PASS : FAIL);
}

static
void test_ms_null_pointer() {
    long long expected = 0ll;
    int *array = NULL;
    size_t length = 1000;

    printf("Null pointer sum: %s\n",
           assert_true(expected == calc_max_sum(array, length)) ? PASS : FAIL);
}

void test_max_sum() {
    puts("TESTS FOR CALC_MAX_SUM:");
    test_ms_functional();
    test_ms_negative_sum();
    test_ms_all_positive();
    test_ms_zero_elements();
    test_ms_null_pointer();
    puts("");
}

/**
 * Main function running all test
 */
int main(void) {
    srand(time(NULL));
    test_passed = 0;

    puts("STARTING UNIT TEST:\n");

    test_create_copy();
    test_heap_sort();
    test_list_insert_node();
    test_egypcian_multiplication();
    test_list_has_cycle();
    test_anagrams();
    test_max_sum();

    printf("Overall test [ PASS / TOTAL ]: [ %d / %d ]\n", test_passed, TOTAL_TEST);

    return EXIT_SUCCESS;
}
