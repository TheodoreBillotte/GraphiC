/*
** EPITECH PROJECT, 2022
** actors_functions
** File description:
** file for actors functions
*/

#include "actors.h"
#include "list.h"
#include "drawables.h"

actor_t *get_actor_list(list_t *list, int id)
{
    node_t *actors = list->head;

    if (!actors)
        return NULL;
    for (actor_t * actor = (actor_t *) actors->data; actors; actors =
                                                    actors->next) {
        if (actor->id == id)
            return actor;
    }
    return NULL;
}

actor_t *actor_loop(graphic_t *graphic, int scene, int id)
{
    for (int layer = 0; layer < graphic->nb_layers; layer++) {
        actor_t *actor = get_actor_list(
            get_scene_drawable(graphic, scene, layer).actors, id);
        if (actor)
            return actor;
    }
    return NULL;
}

actor_t *get_actor(graphic_t *graphic, int id)
{
    for (int scene = 0; scene < graphic->nb_scenes; scene++) {
        actor_t * actor = actor_loop(graphic, scene, id);
        if (actor)
            return actor;
    }
    return NULL;
}
