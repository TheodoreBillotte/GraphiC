/*
** EPITECH PROJECT, 2023
** scenes
** File description:
** header file for scenes functions
*/

#ifndef SCENES
    #define SCENES

    #include "graphic.h"

void set_actor_scene(graphic_t *graphic, actor_t *actor, int scene);
void set_button_scene(graphic_t *graphic, actor_t *button, int scene);
void set_text_scene(graphic_t *graphic, actor_t *text, int scene);

#endif
