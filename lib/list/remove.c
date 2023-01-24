/*
** EPITECH PROJECT, 2023
** remove
** File description:
** file for remove functions for list library
*/

#include <malloc.h>
#include "list.h"

void list_remove_node(list_t * list, node_t * node, bool free_data)
{
    if (node->prev)
        node->prev->next = node->next;
    else
        list->head = node->next;
    if (node->next)
        node->next->prev = node->prev;
    else
        list->tail = node->prev;

    if (free_data)
        free(node->data);
    free(node);
    list->size--;
}

void list_remove(list_t * list, int index, bool free_data)
{
    node_t * node = list_get_node(list, index);
    if (node)
        list_remove_node(list, node, free_data);
}

void list_remove_data(list_t * list, void * data, bool free_data)
{
    node_t * node = list->head;
    while (node) {
        if (node->data == data) {
            list_remove_node(list, node, free_data);
            return;
        }
        node = node->next;
    }
}
