/*
** EPITECH PROJECT, 2023
** list
** File description:
** header file for list library
*/

#ifndef LIST
    #define LIST

    #include <stdbool.h>

typedef struct node_s {
    void * data;
    struct node_s * next;
    struct node_s * prev;
} node_t;

typedef struct list_s {
    node_t * head;
    node_t * tail;
    int size;
} list_t;

list_t * create_list(void);
node_t * create_node(void * data);

void list_append(list_t * list, void * data);
void list_append_list(list_t * list, list_t * to_append);

void list_free(list_t * list, bool free_data);
void list_free_nodes(list_t * list, bool free_data);

void list_clear(list_t * list, bool free_data);

list_t * list_copy(list_t * list);

int list_size(list_t * list);
int list_count(list_t * list, void * data);
int list_count_func(list_t * list, int (*equals)(void *));

void * list_get(list_t * list, int index);
node_t * list_get_node(list_t * list, int index);

void list_remove_node(list_t * list, node_t * node, bool free_data);
void list_remove_data(list_t * list, void * data, bool free_data);
void list_remove(list_t * list, int index, bool free_data);

int list_index(list_t * list, void * data);
int list_index_node(list_t * list, node_t * node);

void list_swap_datas(node_t * node1, node_t * node2);
void list_swap_nodes(list_t * list, node_t * node1, node_t * node2);
void list_swap(list_t * list, int index1, int index2);

void * list_pop(list_t * list, int index);

void list_insert(list_t * list, void * data, int index);

void list_reverse(list_t * list);

#endif
