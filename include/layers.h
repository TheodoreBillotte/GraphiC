/*
** EPITECH PROJECT, 2023
** layers
** File description:
** header file for layers functions
*/

#ifndef LAYERS
    #define LAYERS

    #include "graphic.h"

void set_actor_layer(graphic_t *graphic, actor_t *actor, int layer);
void set_button_layer(graphic_t *graphic, actor_t *button, int layer);
void set_text_layer(graphic_t *graphic, actor_t *text, int layer);

#endif
