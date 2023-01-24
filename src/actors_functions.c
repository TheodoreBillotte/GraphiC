/*
** EPITECH PROJECT, 2022
** actors_functions
** File description:
** file for actors functions
*/

#include "actors.h"

actor_t * get_actor(graphic_t * graphic, int id)
{
    node_t * actors = graphic->actors->head;

    while (actors) {
        actor_t * actor = (actor_t *) actors->data;
        if (actor->id == id)
            return actor;
        actors = actors->next;
    }
    return NULL;
}
