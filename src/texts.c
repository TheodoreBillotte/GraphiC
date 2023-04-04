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
#include "drawables.h"
#include "texts.h"

text_t *build_text(graphic_t * graphic, int font_id, int scene, int layer)
{
    text_t * t = malloc(sizeof(text_t));
    sfText * text = sfText_create();
    sfFont * font = get_font(graphic, font_id)->font;

    if (!text || !font)
        return NULL;
    sfText_setFont(text, font);
    t->id = graphic->ids->text_id++;
    t->text = text;
    t->scene = scene;
    t->layer = layer;
    if (scene != -1)
        list_append(get_scene_drawable(graphic, scene, layer).texts, t);
    else
        list_append(graphic->ui_layers[layer].texts, t);
    return t;
}

void destroy_text(text_t * text)
{
    sfText_destroy(text->text);
    free(text);
}

void destroy_text_list(list_t * list)
{
    node_t * node = list->head;

    for (; node; node = node->next)
        destroy_text(node->data);
    list_free(list, false);
}
