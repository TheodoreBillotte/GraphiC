/*
** EPITECH PROJECT, 2023
** textures
** File description:
** header file for textures functions
*/

#ifndef TEXTURES
    #define TEXTURES

    #include "graphic.h"

texture_t * build_texture(graphic_t *, char * path);
texture_t * get_texture(graphic_t * graphic, int id);
void destroy_texture(texture_t * texture);

#endif
