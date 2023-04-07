/*
** EPITECH PROJECT, 2023
** ids
** File description:
** file for ids functions
*/

#include <malloc.h>
#include "ids.h"

ids_t * build_ids(void)
{
    ids_t * ids = malloc(sizeof(ids_t));

    *ids = (ids_t) {0};
    return ids;
}
