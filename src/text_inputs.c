/*
** EPITECH PROJECT, 2023
** text_input
** File description:
** file for text input functions
*/

#include <malloc.h>
#include "text_inputs.h"

text_input_t *build_text_input(graphic_t *graphic,
                            text_input_constructor_t constructor)
{
    text_input_t *text_input = malloc(sizeof(text_input_t));

    *text_input = (text_input_t) {0};
    text_input->bg = sfRectangleShape_create();
    text_input->text = sfText_create();
    text_input->scene = constructor.scene;
    text_input->layer = constructor.layer;
    text_input->max_char = constructor.max_char;
    text_input->id = graphic->ids->text_input_id++;
    text_input->content = malloc(sizeof(char) * (text_input->max_char + 1));
    text_input->content[0] = '\0';
    text_input->is_visible = true;
    setup_text_input(graphic, text_input, constructor);
    text_input->rect = sfText_getGlobalBounds(text_input->text);
    list_append(get_drawable(graphic, text_input->layer).text_inputs,
                text_input);
    return text_input;
}

void setup_text_input(graphic_t *graphic, text_input_t *text_input,
                    text_input_constructor_t constructor)
{
    sfRectangleShape_setFillColor(text_input->bg, constructor.bg_color);
    sfRectangleShape_setPosition(text_input->bg, constructor.pos);
    sfRectangleShape_setSize(text_input->bg, constructor.size);
    sfText_setString(text_input->text, text_input->content);
    sfText_setFont(text_input->text, get_font(graphic, constructor.font)->font);
    sfText_setCharacterSize(text_input->text, constructor.font_size);
    sfText_setColor(text_input->text, constructor.text_color);
    sfText_setPosition(text_input->text, (sfVector2f) {constructor.pos.x + 5,
                                                    constructor.pos.y + 5});
}

void destroy_text_input(text_input_t *text_input)
{
    sfRectangleShape_destroy(text_input->bg);
    sfText_destroy(text_input->text);
    free(text_input);
}

void destroy_text_input_list(list_t *list)
{
    node_t *node = list->head;

    for (; node; node = node->next)
        destroy_text_input(node->data);
    list_free(list, false);
}

void draw_text_input(graphic_t *graphic, text_input_t *text_input)
{
    if (!text_input->is_visible)
        return;
    sfRenderWindow_drawRectangleShape(graphic->window, text_input->bg, NULL);
    sfRenderWindow_drawText(graphic->window, text_input->text, NULL);
}
