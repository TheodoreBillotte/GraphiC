/*
** EPITECH PROJECT, 2022
** actors
** File description:
** header for actors functions and structure
*/

#ifndef ACTORS
    #define ACTORS

    #include <SFML/Graphics.h>
    #include "animations.h"

actor_t * build_actor(graphic_t *graphic, actor_constructor_t constructor);
void update_actor(graphic_t *graphic, actor_t *actor);
void destroy_actor(actor_t *actor);
void remove_actor(graphic_t *graphic, actor_t *actor);
void draw_actors(graphic_t *graphic);
actor_t * get_actor(graphic_t *graphic, int id);
void destroy_actor_list(list_t *list);

#endif
