/*
** EPITECH PROJECT, 2023
** swap
** File description:
** file for swap functions for list library
*/

#include "list.h"

void list_swap_datas(node_t * node1, node_t * node2)
{
    if (!node1 || !node2)
        return;

    void * tmp = node1->data;
    node1->data = node2->data;
    node2->data = tmp;
}

void list_swap_nodes(list_t * list, node_t * node1, node_t * node2)
{
    node_t * tmp;
    if (!list || !node1 || !node2)
        return;

    tmp = node1->prev;
    if (node1 == list->head)
        list->head = node2;
    if (node1 == list->tail)
        list->tail = node2;
    if (node2 == list->head)
        list->head = node1;
    if (node2 == list->tail)
        list->tail = node1;

    node1->prev = node2->prev;
    node1->next = node2->next;
    node2->prev = tmp->prev;
    node2->next = tmp->next;
}

void list_swap(list_t * list, int index1, int index2)
{
    list_swap_datas(list_get_node(list, index1), list_get_node(list, index2));
}
