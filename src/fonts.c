/*
** EPITECH PROJECT, 2022
** fonts
** File description:
** file for fonts functions
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "graphic.h"
#include "fonts.h"

font_t * build_font(graphic_t *graphic, char * path)
{
    sfFont *font = sfFont_createFromFile(path);
    font_t *new_font = malloc(sizeof(font_t));

    new_font->font = font;
    new_font->id = list_size(graphic->fonts);

    list_append(graphic->fonts, new_font);
    return new_font;
}

font_t * get_font(graphic_t *graphic, int id)
{
    for (node_t * fonts = graphic->fonts->head; fonts; fonts = fonts->next) {
        if (((font_t *) fonts->data)->id == id)
            return (font_t *) fonts->data;
    }
    return NULL;
}

void destroy_font(font_t *font)
{
    sfFont_destroy(font->font);
    free(font);
}
