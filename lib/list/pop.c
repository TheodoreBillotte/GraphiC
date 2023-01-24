/*
** EPITECH PROJECT, 2023
** pop
** File description:
** file for pop functions for list library
*/

#include "list.h"

void * list_pop(list_t * list, int index)
{
    node_t * node = list_get_node(list, index);
    void * data = node->data;
    list_remove_node(list, node, false);
    return data;
}
