/*
** EPITECH PROJECT, 2023
** pop
** File description:
** file for pop functions for list library
*/

#include "list.h"

void * list_pop_node(list_t *list, node_t *node)
{
    void * data = node->data;

    list_remove_node(list, node, false);
    return data;
}

void * list_pop(list_t * list, int index)
{
    return list_pop_node(list, list_get_node(list, index));
}
