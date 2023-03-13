/*
** EPITECH PROJECT, 2023
** insert
** File description:
** file for insert functions for list library
*/

#include "list.h"

void list_insert_before_node(list_t *list, node_t *node, void *data)
{
    node_t * new = create_node(data);
    if (!data || !list)
        return;
    if (!node) {
        list_append_node(list, new);
        return;
    }
    if (node->prev)
        node->prev->next = new;
    else
        list->head = new;
    if (node->next)
        node->next->prev = new;
    else
        list->tail = new;
    new->prev = node->prev;
    new->next = node;
    node->prev = new;
    list->size++;
}

void list_insert(list_t *list, void *data, int index)
{
    node_t * node = list_get_node(list, index);
    list_insert_before_node(list, node, data);
}
