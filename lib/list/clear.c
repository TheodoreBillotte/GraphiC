/*
** EPITECH PROJECT, 2023
** clear
** File description:
** file for clear functions for list library
*/

#include <stddef.h>
#include "list.h"

void list_clear(list_t * list, bool free_data)
{
    list_free_nodes(list, free_data);
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}
