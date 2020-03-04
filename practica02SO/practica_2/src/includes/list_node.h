/*
 * list_node.h
 *
 *  Author: Alaín Chevanier
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

struct list_node {
    int value;
    struct list_node *next;
    struct list_node *rand;
};

int list_find_node(struct list_node *, struct list_node *);

void free_list(struct list_node *);

void create_random_list(struct list_node **, unsigned int);

void create_random_list_with_rand(struct list_node **, unsigned int, int active_random);

int remove_node(struct list_node *, struct list_node **);

void push_front(int, struct list_node **);

void reverse_list(struct list_node **);

void insert_at(int, int, struct list_node **);

int remove_at(int, struct list_node **);

int pop(struct list_node **);

int list_length(struct list_node *);

int get_maximum(struct list_node *);

int get_minimum(struct list_node *);

#endif /* LINKED_LIST_H_ */
