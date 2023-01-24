/*
** EPITECH PROJECT, 2022
** texts
** File description:
** header file for texts functions
*/

#ifndef TEXTS
    #define TEXTS

    #include <SFML/Graphics.h>

    #include "graphic.h"

text_t * build_text(graphic_t * graphic, char * string, int font_id, int size);
void draw_texts(graphic_t * graphic);
void destroy_text(text_t * text);

#endif
