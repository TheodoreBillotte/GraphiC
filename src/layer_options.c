/*
** EPITECH PROJECT, 2023
** layer_options
** File description:
** file for layer options functions
*/

#include <string.h>
#include <malloc.h>
#include "layer_options.h"

int **build_layer_options(graphic_t *game)
{
    int **options = malloc(sizeof(int *) * game->nb_scenes);

    for (int i = 0; i < game->nb_scenes; i++) {
        options[i] = malloc(sizeof(int) * game->nb_layers);
        memset(options[i], 255, sizeof(int) * game->nb_layers);
    }
    return options;
}

int *build_ui_layer_options(graphic_t *game)
{
    int *options = malloc(sizeof(int) * game->nb_layers);
    memset(options, 255, sizeof(int) * game->nb_layers);
    return options;
}
