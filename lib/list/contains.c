/*
** EPITECH PROJECT, 2023
** contains
** File description:
** file for list contains functions
*/

#include "list.h"

int list_contains(list_t *list, void *data)
{
    node_t *nodes = list->head;

    if (!nodes)
        return 0;
    for (void *node_data = nodes->data; nodes; nodes = nodes->next) {
        if (node_data == data)
            return 1;
    }
    return 0;
}
