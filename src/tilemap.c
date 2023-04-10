/*
** EPITECH PROJECT, 2023
** tilemap
** File description:
** file for tilemap functions
*/

#include "csv.h"
#include "tilemap.h"
#include "textures.h"
#include "drawables.h"

static void draw_tm(graphic_t *graphic, sfVector2i pos, tilemap_t *tm,
                        int **map)
{
    int ts = tm->tile_size;
    int i = pos.x;
    int j = pos.y;

    if (map[i][j] == -1)
        return;
    sfSprite_setPosition(tm->sprite,
            (sfVector2f) {tm->pos.x + (float) j * (float) ts *tm->scale.x,
                        tm->pos.y + (float) i * (float) ts * tm->scale.y});
    sfSprite_setTextureRect(tm->sprite,
        (sfIntRect) {(map[i][j] % (int) tm->tiles_count.x) * ts,
        (map[i][j] / (int) tm->tiles_count.x) * ts, ts, ts});
    sfRenderWindow_drawSprite(graphic->window, tm->sprite, NULL);
}

tilemap_t *build_tilemap(graphic_t *graphic, tilemap_constructor_t constructor)
{
    tilemap_t *tm = malloc(sizeof(tilemap_t));
    int **csv = transform_csv(get_csv(constructor.csv_path, ','));
    tm->texture = get_texture(graphic, constructor.texture)->texture;
    tm->tile_size = constructor.tile_size;
    tm->scene = constructor.scene;
    tm->layer = constructor.layer;
    tm->scale = constructor.scale;
    tm->pos = constructor.pos;
    tm->map = csv;
    tm->sprite = sfSprite_create();
    sfSprite_setTexture(tm->sprite, tm->texture, sfTrue);
    sfSprite_setScale(tm->sprite, tm->scale);
    tm->tiles_count = sfTexture_getSize(tm->texture);
    tm->tiles_count = (sfVector2u) {tm->tiles_count.x / tm->tile_size,
                                    tm->tiles_count.y / tm->tile_size};
    if (tm->scene == -1)
        list_append(graphic->ui_layers[tm->layer].tilemaps, tm);
    else
        list_append(get_drawable(graphic, tm->layer).tilemaps, tm);
    return tm;
}

void draw_tilemap(graphic_t *graphic, tilemap_t *tilemap)
{
    for (int i = 0; tilemap->map[i]; i++)
        for (int j = 0; tilemap->map[i][j] != -2; j++)
            draw_tm(graphic, (sfVector2i) {i, j}, tilemap, tilemap->map);
}

void destroy_tilemap(tilemap_t *tilemap)
{
    sfSprite_destroy(tilemap->sprite);
    free_csv_int(tilemap->map);
    free(tilemap);
}

void destroy_tilemap_list(list_t *list)
{
    for (node_t *node = list->head; node; node = node->next)
        destroy_tilemap((tilemap_t *) node->data);
    list_free(list, false);
}
