/*
** EPITECH PROJECT, 2023
** tilemap
** File description:
** file for tilemap functions
*/

#ifndef TILEMAP_H
    #define TILEMAP_H

    #include "graphic.h"

tilemap_t *build_tilemap(graphic_t *graphic, tilemap_constructor_t constructor);
void draw_tilemap(graphic_t *graphic, tilemap_t *tilemap);
void destroy_tilemap(tilemap_t *tilemap);
void destroy_tilemap_list(list_t *list);

#endif
