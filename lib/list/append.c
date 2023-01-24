/*
** EPITECH PROJECT, 2023
** append
** File description:
** file for append functions for list library
*/

#include "list.h"

void list_append(list_t * list, void * data)
{
    node_t * node = create_node(data);
    if (!list)
        return;

    list->size++;
    if (!list->tail) {
        list->tail = node;
        list->head = node;
    } else {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }
}

void list_append_list(list_t * list, list_t * to_append)
{
    to_append->head->prev = list->tail;
    list->tail->next = to_append->head;
    list->tail = to_append->tail;
    list->size += to_append->size;
}
