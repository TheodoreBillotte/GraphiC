/*
** EPITECH PROJECT, 2023
** get
** File description:
** file for get functions for list library
*/

#include <stddef.h>
#include "list.h"

void * list_get(list_t * list, int index)
{
    node_t * node;

    if (index < 0) {
        if (index < -list->size)
            return NULL;

        node = list->tail;
        for (int i = -1; i > index; i--)
            node = node->prev;
    } else {
        if (index >= list->size)
            return NULL;

        node = list->head;
        for (int i = 0; i < index; i++)
            node = node->next;
    }
    return node->data;
}

node_t * list_get_node(list_t * list, int index)
{
    node_t * node;

    if (index < 0) {
        if (index < -list->size)
            return NULL;

        node = list->tail;
        for (int i = -1; i > index; i--)
            node = node->prev;
    } else {
        if (index >= list->size)
            return NULL;

        node = list->head;
        for (int i = 0; i < index; i++)
            node = node->next;
    }
    return node;
}
