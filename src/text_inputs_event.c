/*
** EPITECH PROJECT, 2023
** text_inputs_event
** File description:
** file for text inputs event functions
*/

#include "text_inputs.h"

void text_input_click(graphic_t *graphic, text_input_t *text_input,
                        sfMouseButtonEvent button)
{
    if (!text_input->is_visible)
        return;
    text_input->rect = sfRectangleShape_getGlobalBounds(text_input->bg);
    text_input->is_selected = sfFloatRect_contains(&text_input->rect,
                                                    button.x, button.y);
    if (text_input->on_click)
        text_input->on_click(graphic, text_input, button);
}

void text_input_key_pressed(graphic_t *graphic, text_input_t *text_input,
                        sfTextEvent event)
{
    if (!text_input->is_selected || !text_input->is_visible)
        return;
    if (event.unicode == 27)
        text_input->is_selected = false;
    if (event.unicode == 13) {
        if (text_input->on_validate)
            text_input->on_validate(graphic, text_input);
        text_input->is_selected = false;
        text_input->cursor = 0;
        text_input->content[0] = '\0';
    }
    if (event.unicode == 8)
        if (text_input->cursor > 0)
            text_input->content[text_input->cursor-- - 1] = '\0';
    if (event.unicode >= 32 && event.unicode <= 126 && text_input->cursor <
            text_input->max_char) {
        text_input->content[text_input->cursor++] = event.unicode;
        text_input->content[text_input->cursor] = '\0';
    }
    sfText_setString(text_input->text, text_input->content);
}

void text_input_release(graphic_t *graphic, text_input_t *text_input,
                        sfMouseButtonEvent button)
{
    if (!text_input->is_selected || text_input->is_visible ||
        !sfFloatRect_contains(&text_input->rect, button.x, button.y))
        return;
    if (text_input->on_release)
        text_input->on_release(graphic, text_input, button);
}
