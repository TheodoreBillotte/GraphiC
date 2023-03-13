/*
** EPITECH PROJECT, 2023
** sliders_functions
** File description:
** file for sliders functions functions
*/

#include <malloc.h>
#include "sliders.h"

void destroy_slider_list(list_t *list)
{
    for (node_t *node = list->head; node; node = node->next)
        destroy_slider((slider_t *) node->data);
    list_free(list, false);
}

void destroy_slider(slider_t *slider)
{
    sfSprite_destroy(slider->bar);
    sfSprite_destroy(slider->scroller);
    free(slider);
}
