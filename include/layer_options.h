/*
** EPITECH PROJECT, 2023
** layer_option
** File description:
** file for layer option functions
*/

#ifndef LAYER_OPTIONS_H
    #define LAYER_OPTIONS_H

    #include "graphic.h"

    #define GET_LAYER_OPTION(graphic, layer, x) \
        (((graphic)->layers_options[(graphic)->scene][(layer)]) & (1 << (x)))
    #define SWITCH_LAYER_OPTION(graphic, layer, x) \
        (((graphic)->layers_options[(graphic)->scene][(layer)]) ^= (1 << (x)))

    #define GET_UI_LAYER_OPTION(graphic, layer, x) \
        (((graphic)->ui_layers_options[(layer)]) & (1 << (x)))
    #define SWITCH_UI_LAYER_OPTION(graphic, layer, x) \
        (((graphic)->ui_layers_options[(layer)]) ^= (1 << (x)))

int **build_layer_options(graphic_t *game);
int *build_ui_layer_options(graphic_t *game);

#endif
