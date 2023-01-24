/*
** EPITECH PROJECT, 2023
** count
** File description:
** file for count functions for list library
*/

#include "list.h"

int list_size(list_t * list)
{
    return list->size;
}

int list_count(list_t * list, void * data)
{
    int count = 0;
    node_t * node = list->head;

    while (node) {
        if (node->data == data)
            count++;
        node = node->next;
    }
    return count;
}

int list_count_func(list_t * list, int (*equals)(void *))
{
    int count = 0;
    node_t * node = list->head;

    while (node) {
        if (equals(node->data))
            count++;
        node = node->next;
    }
    return count;
}
