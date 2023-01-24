/*
** EPITECH PROJECT, 2023
** free
** File description:
** file for free functions for list library
*/

#include <stdlib.h>

#include "list.h"

void list_free(list_t * list, bool free_data)
{
    node_t * node = list->head;
    node_t * tmp = NULL;

    while (node) {
        tmp = node;
        node = node->next;
        if (free_data)
            free(tmp->data);
    }
    free(list);
}

void list_free_nodes(list_t * list, bool free_data)
{
    node_t * node = list->head;
    node_t * tmp = NULL;

    while (node) {
        tmp = node;
        node = node->next;
        if (free_data)
            free(tmp->data);
        free(tmp);
    }
}
