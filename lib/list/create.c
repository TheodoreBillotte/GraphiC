/*
** EPITECH PROJECT, 2023
** create
** File description:
** file for create functions for list library
*/

#include <malloc.h>
#include "list.h"

list_t * create_list(void)
{
    list_t * list = malloc(sizeof(list_t));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

node_t * create_node(void * data)
{
    node_t * node = malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
