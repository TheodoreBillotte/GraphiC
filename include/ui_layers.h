/*
** EPITECH PROJECT, 2023
** ui_layers
** File description:
** file for ui layers functions
*/

#ifndef UI_LAYERS_H
    #define UI_LAYERS_H

    #include <malloc.h>
    #include "graphic.h"

drawables_t *build_ui_layers(graphic_t *graphic);
void draw_ui_layers(graphic_t *graphic);
void draw_ui_layers_next(graphic_t *graphic, int layer);
void destroy_ui_layers(graphic_t *graphic);

#endif
