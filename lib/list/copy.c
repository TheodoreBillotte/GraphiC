/*
** EPITECH PROJECT, 2023
** copy
** File description:
** file for copy functions for list library
*/

#include "list.h"

list_t * list_copy(list_t * list)
{
    list_t * new_list = create_list();
    node_t * node = list->head;

    while (node) {
        list_append(new_list, node->data);
        node = node->next;
    }
    return new_list;
}
