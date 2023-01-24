/*
** EPITECH PROJECT, 2023
** index
** File description:
** file for index functions for list library
*/

#include "list.h"

int list_index(list_t * list, void * data)
{
    node_t * node = list->head;
    int i = 0;

    while (node) {
        if (node->data == data)
            return i;
        node = node->next;
        i++;
    }
    return -1;
}

int list_index_node(list_t * list, node_t * node)
{
    node_t * tmp = list->head;
    int i = 0;

    while (tmp) {
        if (tmp == node)
            return i;
        tmp = tmp->next;
        i++;
    }
    return -1;
}
