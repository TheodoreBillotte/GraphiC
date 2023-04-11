/*
** EPITECH PROJECT, 2023
** collides
** File description:
** file for collides functions
*/

#include <stdio.h>
#include "collides.h"

static sfFloatRect collide(int i, tilemap_t *tm, sfFloatRect rect)
{
    sfFloatRect tile;
    sfFloatRect collide;

    for (int j = 0; tm->map[i][j] != -2; j++) {
        if (tm->map[i][j] == -1)
            continue;
        tile = (sfFloatRect) {
            tm->pos.x + j * tm->tile_size * tm->scale.x,
            tm->pos.y + i * tm->tile_size * tm->scale.y,
            tm->tile_size * tm->scale.x,
            tm->tile_size * tm->scale.y};
        if (sfFloatRect_intersects(&rect, &tile, &collide))
            return collide;
    }
    tile = (sfFloatRect) {0, 0, 0, 0};
    return tile;
}

sfFloatRect check_collides(tilemap_t *tm, sfFloatRect rect)
{
    sfFloatRect tile;

    for (int i = 0; tm->map[i]; i++) {
        tile = collide(i, tm, rect);
        if (tile.width != 0 && tile.height != 0)
            return tile;
    }
    tile = (sfFloatRect) {0, 0, 0, 0};
    return tile;
}
