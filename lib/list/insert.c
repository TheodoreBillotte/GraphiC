/*
** EPITECH PROJECT, 2023
** insert
** File description:
** file for insert functions for list library
*/

#include "list.h"

void list_insert(list_t * list, void * data, int index)
{
    node_t * node = list_get_node(list, index);
    node_t * new = create_node(data);

    if (!node) {
        list_append(list, data);
        return;
    }

    if (index == 0)
        list->head = new;

    new->prev = node->prev;
    new->next = node;
    node->prev->next = new;
    node->prev = new;
    list->size++;
}
