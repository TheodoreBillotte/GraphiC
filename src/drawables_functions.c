/*
** EPITECH PROJECT, 2023
** drawables_functions
** File description:
** file for drawables functions
*/

#include "graphic.h"
#include "drawables.h"

void draw_others(graphic_t *graphic, int layer)
{
    for (node_t *list = get_drawable(graphic, layer).sliders->head; list;
                list = list->next) {
        sfRenderWindow_drawSprite(graphic->window,
                                ((slider_t *) list->data)->bar, NULL);
        sfRenderWindow_drawSprite(graphic->window,
                                ((slider_t *) list->data)->scroller, NULL);
    }
}
