/*
** EPITECH PROJECT, 2023
** drawables
** File description:
** header file for drawables functions
*/

#ifndef DRAWABLES
    #define DRAWABLES

    #include "graphic.h"

drawables_t **create_drawables(int nb_scenes, int nb_layers);
drawables_t get_scene_drawable(graphic_t *graphic, int scene, int layer);
drawables_t get_drawable(graphic_t *graphic, int layer);
void draw_others(graphic_t *graphic, int layer);
void destroy_drawables(graphic_t *graphic);
void draw_game(graphic_t *graphic);

#endif
