/*
** EPITECH PROJECT, 2022
** actors
** File description:
** actors functions files
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>

#include "actors.h"
#include "graphic.h"
#include "textures.h"
#include "drawables.h"

actor_t * build_actor(graphic_t *graphic, int texture_id,
                    int scene, int layer)
{
    actor_t * actor = malloc(sizeof(actor_t));

    actor->sprite = sfSprite_create();
    actor->layer = 0;
    actor->scene = scene;
    actor->id = graphic->ids->actor_id++;
    actor->animation = NULL;
    actor->update = NULL;
    sfSprite_setTexture(actor->sprite,
                        get_texture(graphic, texture_id)->texture, sfTrue);
    actor->rect = sfSprite_getGlobalBounds(actor->sprite);
    list_append(get_scene_drawable(graphic, scene, layer).actors, actor);
    return actor;
}

void update_actor(graphic_t *graphic, actor_t *actor)
{
    play_animation(actor);
    if (actor->update)
        actor->update(graphic, actor);
}

void destroy_actor(actor_t *actor)
{
    if (!actor)
        return;
    sfSprite_destroy(actor->sprite);
    if (actor->animation)
        destroy_animation(actor->animation);
    free(actor);
}

void destroy_actor_list(list_t *list)
{
    node_t *node = list->head;

    for (; node; node = node->next)
        destroy_actor(node->data);
    list_free(list, false);
}

void remove_actor(graphic_t *graphic, actor_t *actor)
{
    node_t *list = graphic->drawables[actor->scene][actor->layer].actors->head;
    int i = 0;

    for (; list; list = list->next, i++) {
        if (actor == list->data) {
            destroy_actor(actor);
            list_remove_node(graphic->drawables[actor->scene][actor->layer]
                            .actors, list, false);
            return;
        }
    }
}
