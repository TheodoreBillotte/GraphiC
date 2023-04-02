/*
** EPITECH PROJECT, 2023
** collides
** File description:
** file for collides functions
*/

#include <stdio.h>
#include "collides.h"
#include "drawables.h"

sfFloatRect check_collides(graphic_t *graphic, int layer, sfFloatRect rect)
{
    sfFloatRect diff = {0, 0, 0, 0};

    for (node_t *drawables = get_drawable(graphic, layer).actors->head;
        drawables; drawables = drawables->next) {
        actor_t *actor = (actor_t *) drawables->data;
        sfFloatRect bounds = sfSprite_getGlobalBounds(actor->sprite);
        if (sfFloatRect_intersects(&rect, &bounds, &diff))
            return diff;
    }
    return diff;
}
