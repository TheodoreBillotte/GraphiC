/*
** EPITECH PROJECT, 2022
** texts
** File description:
** files for texts functions
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "graphic.h"
#include "fonts.h"

text_t * build_text(graphic_t * graphic, char * string, int font_id, int size)
{
    text_t * t = malloc(sizeof(text_t));
    sfText * text = sfText_create();
    sfFont * font = get_font(graphic, font_id)->font;

    if (!text || !font)
        return NULL;

    sfText_setString(text, string);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);

    t->id = list_size(graphic->texts);
    t->text = text;

    list_append(graphic->texts, t);
    return t;
}

void draw_texts(graphic_t * graphic)
{
    for (node_t * texts = graphic->texts->head; texts; texts = texts->next) {
        text_t * text = (text_t *) texts->data;
        sfRenderWindow_drawText(graphic->window, text->text, NULL);
    }
}

void destroy_text(text_t * text)
{
    sfText_destroy(text->text);
    free(text);
}
