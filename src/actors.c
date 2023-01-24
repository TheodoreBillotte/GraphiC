/*
** EPITECH PROJECT, 2022
** actors
** File description:
** actors functions files
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <math.h>
#include <stdlib.h>

#include "actors.h"
#include "graphic.h"
#include "textures.h"

actor_t * build_actor(graphic_t * graphic, int texture_id, sfVector2f position,
                    int scene)
{
    actor_t * actor = malloc(sizeof(actor_t));

    actor->sprite = sfSprite_create();
    actor->layer = 0;
    actor->scene = scene;
    actor->id = graphic->sprite_id++;
    actor->animation = NULL;

    sfSprite_setTexture(actor->sprite,
                        get_texture(graphic, texture_id)->texture, sfTrue);
    actor->rect = sfSprite_getGlobalBounds(actor->sprite);

    list_append(graphic->actors, actor);
    return actor;
}

void update_actor(actor_t * actor)
{
    play_animation(actor);
}

void destroy_actor(actor_t * actor)
{
    if (!actor)
        return;

    sfSprite_destroy(actor->sprite);
    if (actor->animation)
        destroy_animation(actor->animation);
    free(actor);
}

void remove_actor(graphic_t * graphic, int id)
{
    node_t * list = graphic->actors->head;
    actor_t * actor;
    int i = 0;

    for (; list; list = list->next, i++) {
        actor = list->data;
        if (actor->id == id) {
            destroy_actor(actor);
            list_remove_node(graphic->actors, list, false);
            return;
        }
    }
}

void draw_actors(graphic_t * graphic)
{
    for (node_t * list = graphic->actors->head; list; list = list->next) {
        actor_t * actor = (actor_t *) list->data;
        if (actor->scene == graphic->scene)
            sfRenderWindow_drawSprite(graphic->window, actor->sprite, NULL);
    }
}
