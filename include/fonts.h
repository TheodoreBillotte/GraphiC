/*
** EPITECH PROJECT, 2022
** fonts
** File description:
** header file for fonts functions
*/

#ifndef FONTS
    #define FONTS

    #include "graphic.h"

font_t * build_font(graphic_t *graphic, char * path);
font_t * get_font(graphic_t * graphic, int id);
void destroy_font(font_t * font);

#endif
