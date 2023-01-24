/*
** EPITECH PROJECT, 2023
** reverse
** File description:
** file for reverse functions for list library
*/

#include "list.h"

void list_reverse(list_t * list)
{
    node_t * node = list->head;
    node_t * tmp;

    while (node) {
        tmp = node->next;
        node->next = node->prev;
        node->prev = tmp;
        node = tmp;
    }
    tmp = list->head;
    list->head = list->tail;
    list->tail = tmp;
}
