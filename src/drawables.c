/*
** EPITECH PROJECT, 2023
** drawables
** File description:
** file for drawables functions
*/

#include <malloc.h>
#include "drawables.h"
#include "list.h"
#include "actors.h"
#include "buttons.h"
#include "texts.h"

drawables_t **create_drawables(int nb_scenes, int nb_layers)
{
    drawables_t **drawables = malloc(sizeof(drawables_t*) * nb_layers);
    for (int i = 0; i < nb_layers; i++) {
        drawables[i] = malloc(sizeof(drawables_t) * nb_scenes);
        for (int j = 0; j < nb_scenes; j++) {
            drawables[i][j].actors = create_list();
            drawables[i][j].buttons = create_list();
            drawables[i][j].texts = create_list();
        }
    }
    return drawables;
}

drawables_t get_drawable(graphic_t *graphic, int layer)
{
    return graphic->drawables[graphic->scene][layer];
}

drawables_t get_scene_drawable(graphic_t *graphic, int scene, int layer)
{
    return graphic->drawables[scene][layer];
}

void draw_game(graphic_t *graphic)
{
    for (int i = 0; i < graphic->nb_layers; i++) {
        for (node_t *list = get_drawable(graphic, i).actors->head; list;
                    list = list->next)
            sfRenderWindow_drawSprite(graphic->window,
                            ((actor_t *) list->data)->sprite, NULL);
        for (node_t *list = get_drawable(graphic, i).buttons->head; list;
                    list = list->next)
            sfRenderWindow_drawSprite(graphic->window,
                            ((button_t *) list->data)->sprite, NULL);
        for (node_t *list = get_drawable(graphic, i).texts->head; list;
                    list = list->next)
            sfRenderWindow_drawText(graphic->window,
                            ((text_t *) list->data)->text, NULL);
    }
}

void destroy_drawables(graphic_t *graphic)
{
    for (int i = 0; i < graphic->nb_layers; i++) {
        for (int j = 0; j < graphic->nb_scenes; j++) {
            destroy_actor_list(graphic->drawables[i][j].actors);
            destroy_button_list(graphic->drawables[i][j].buttons);
            destroy_text_list(graphic->drawables[i][j].texts);
        }
        free(graphic->drawables[i]);
    }
    free(graphic->drawables);
}
