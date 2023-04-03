/*
** EPITECH PROJECT, 2023
** tilemap
** File description:
** file for tilemap functions
*/

#include "csv.h"
#include "actors.h"
#include "tilemap.h"

static void create_tilemap(graphic_t *graphic, sfVector2i pos,
                        tilemap_constructor_t constructor, int **map)
{
    int ts = constructor.tile_size;
    actor_t *actor;
    int i = pos.x;
    int j = pos.y;

    if (map[i][j] == -1)
        return;
    actor = build_actor(graphic, (actor_constructor_t) {
            .position = (sfVector2f) {constructor.pos.x + j * ts,
                                    constructor.pos.y + i * ts},
            .scale = (sfVector2f) {1, 1},
            .texture = constructor.texture,
            .layer = constructor.layer,
            .scene = constructor.scene
    });
    sfSprite_setTextureRect(actor->sprite,
        (sfIntRect) {(map[i][j] % (int) constructor.size.x) * ts,
        (map[i][j] / (int) constructor.size.x) * ts, ts, ts});
}

void build_tilemap(graphic_t *graphic, tilemap_constructor_t constructor)
{
    csv_t *csv = get_csv(constructor.csv_path);

    for (int i = 0; i < csv->size.x; i++)
        for (int j = 0; j < csv->size.y; j++)
            create_tilemap(graphic, (sfVector2i) {i, j}, constructor, csv->csv);
    free_csv(csv);
}
