/*
 * list_node.c
 *
 *  Author: Alaín CHevanier
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "includes/list_node.h"
#include "includes/booleans.h"

/*
 * Returns the index at which a given node is in a list.
 * If the node is not found within the list, then this
 * function return -1.
 */
int list_find_node(struct list_node *list,
                   struct list_node *node) {
    if (node == NULL) {
        return -1;
    }

    int i = 0;
    while (list != NULL) {
        if (list == node) {
            return i;
        }
        list = list->next;
        i++;
    }

    return -1;
}

void free_list(struct list_node *list) {
    struct list_node *tmp;

    while (list != NULL) {
        tmp = list->next;
        free(list);
        list = tmp;
    }
}

void create_random_list_with_rand(struct list_node **list, unsigned int length, int active_random) {
    int i;

    if (list == NULL || length == 0) {
        return;
    }

    struct list_node **tmp = list;

    for (i = 0; i < length; i++, list = &((*list)->next)) {
        *list = (struct list_node *) malloc(sizeof(struct list_node));
        if (*list == NULL) {
            puts("Error getting memory to allocate a new node");
            exit(-1);
        }

        (*list)->value = rand() % 100000;
        (*list)->next = NULL;
        (*list)->rand = NULL;
    }

    int *array_rand_pos;
    struct list_node **array_node_ref;
    if (active_random) {
        array_rand_pos = (int *) malloc(sizeof(int) * length);
        array_node_ref = (struct list_node **) malloc(sizeof(struct list_node *) * length);

        for (i = 0; i < length; i++, tmp = &((*tmp)->next)) {
            array_rand_pos[i] = rand() % length;
            array_node_ref[i] = *tmp;
        }

        for (i = 0; i < length; i++) {
            array_node_ref[i]->rand = array_node_ref[array_rand_pos[i]];
        }

        free(array_rand_pos);
        free(array_node_ref);
    }
}

void create_random_list(struct list_node **list, unsigned int length) {
    create_random_list_with_rand(list, length, 0);
}

int remove_node(struct list_node *element, struct list_node **list) {
    struct list_node *tmp;

    assert(list != NULL);
    assert(element != NULL);

    if (*list == NULL) {
        return FALSE;
    }

    if (*list == element) {
        tmp = *list;
        *list = (*list)->next;
        free(tmp);

        return TRUE;
    }

    while ((*list)->next != NULL) {
        if ((*list)->next == element) {
            tmp = (*list)->next;
            (*list)->next = (*list)->next->next;
            free(tmp);

            return TRUE;
        }
    }

    return FALSE;
}

void insert_at(int value, int position, struct list_node **plist) {
    assert(plist != NULL);
    assert(position >= 0);

    struct list_node *tmp;
    int i = position;

    while (*plist != NULL && i > 0) {
        plist = &(*plist)->next;
        i--;
    }

    assert(i == 0);

    tmp = (struct list_node *) malloc(sizeof(struct list_node));
    if (tmp == NULL) {
        puts("Failed getting memory to allocate a new node");
        exit(-1);
    }
    tmp->value = value;
    tmp->next = *plist;
    *plist = tmp;
}

void push_front(int value, struct list_node **plist) {
    insert_at(value, 0, plist);
}

static struct list_node *
aux_rev(struct list_node *prev, struct list_node *cur) {
    if (cur == NULL) {
        return prev;
    }

    struct list_node *ncur;
    ncur = cur->next;
    cur->next = prev;

    return aux_rev(cur, ncur);
}

void reverse_list(struct list_node **plist) {
    assert(plist != NULL);

    struct list_node *tmp = *plist;

    *plist = aux_rev(NULL, tmp);
}

int remove_at(int position, struct list_node **plist) {
    assert(position >= 0);
    assert(plist != NULL);

    int i = position;
    int value;
    struct list_node *target;

    while (*plist != NULL && i > 0) {
        plist = &((*plist)->next);
        i--;
    }

    assert(*plist != NULL);
    assert(i == 0);

    target = *plist;
    *plist = (*plist)->next;
    value = target->value;
    free(target);

    return value;
}

int pop(struct list_node **plist) {
    return remove_at(0, plist);
}

int get_maximum(struct list_node *list) {
    int maximum;

    assert(list != NULL);

    maximum = list->value;
    while (list != NULL) {
        if (maximum < list->value) {
            maximum = list->value;
        }
        list = list->next;
    }
    return maximum;
}

int get_minimum(struct list_node *list) {
    int minimum;

    assert(list != NULL);

    minimum = list->value;
    while (list != NULL) {
        if (minimum > list->value) {
            minimum = list->value;
        }
        list = list->next;
    }
    return minimum;
}

int list_length(struct list_node *list) {
    int length = 0;

    while (list) {
        length++;
        list = list->next;
    }

    return length;
}
