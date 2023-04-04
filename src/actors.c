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

actor_t * build_actor(graphic_t *graphic, actor_constructor_t constructor)
{
    actor_t * actor = malloc(sizeof(actor_t));

    actor->sprite = sfSprite_create();
    actor->layer = 0;
    actor->scene = constructor.scene;
    actor->id = graphic->ids->actor_id++;
    actor->animation = constructor.animation;
    actor->update = NULL;
    sfSprite_setTexture(actor->sprite,
        get_texture(graphic, constructor.texture)->texture, sfTrue);
    sfSprite_setPosition(actor->sprite, constructor.position);
    sfSprite_setScale(actor->sprite, constructor.scale);
    play_animation(actor);
    actor->rect = sfSprite_getGlobalBounds(actor->sprite);
    if (constructor.scene != -1)
        list_append(get_scene_drawable(graphic,
            constructor.scene, constructor.layer).actors, actor);
    else
        list_append(graphic->ui_layers[constructor.layer].actors, actor);
    return actor;
}

void update_actor(graphic_t *graphic, actor_t *actor)
{
    check_animation(actor);
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
