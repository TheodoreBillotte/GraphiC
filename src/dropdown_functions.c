/*
** EPITECH PROJECT, 2023
** dropdown_functions
** File description:
** file for dropdown functions
*/

#include "dropdown.h"
#include "events.h"

void cond_click_dropdown(graphic_t *graphic, dropdown_t *dropdown,
                            sfMouseButtonEvent mouse)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(dropdown->sprite);
    if (sfFloatRect_contains(&rect, mouse.x, mouse.y)) {
        dropdown->state = dropdown->state == CLOSED ? OPENED : CLOSED;
        if (dropdown->on_click)
            dropdown->on_click(graphic, dropdown, mouse);
        return;
    }
    rect = sfRectangleShape_getGlobalBounds(dropdown->bg);
    if (dropdown->state == OPENED &&
        sfFloatRect_contains(&rect, mouse.x, mouse.y)) {
        for (node_t *node = dropdown->buttons->head; node; node = node->next)
            cond_click_button(graphic, mouse, node->data);
    }
    dropdown->state = CLOSED;
}

void cond_dropdown_hover(graphic_t *graphic, sfVector2i mouse,
                        dropdown_t *dropdown)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(dropdown->sprite);

    if (sfFloatRect_contains(&rect, (float) mouse.x, (float) mouse.y)) {
        if (dropdown->on_hover)
            dropdown->on_hover(graphic, dropdown);
        return;
    }
    if (dropdown->state == OPENED) {
        for (node_t *node = dropdown->buttons->head; node; node = node->next)
            cond_hover(graphic, mouse, node->data);
        return;
    }
}

void cond_dropdown_release(graphic_t *graphic, dropdown_t *dropdown,
                sfMouseButtonEvent button)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(dropdown->sprite);

    if (sfFloatRect_contains(&rect, (float) button.x, (float) button.y)) {
        if (dropdown->on_release)
            dropdown->on_release(graphic, dropdown, button);
        return;
    }
    if (dropdown->state == OPENED) {
        for (node_t *node = dropdown->buttons->head; node; node = node->next)
            check_release(graphic, button, node->data);
        return;
    }
}

void draw_dropdown(graphic_t *graphic, dropdown_t *dropdown)
{
    sfRenderWindow_drawSprite(graphic->window, dropdown->sprite, NULL);
    if (dropdown->state == OPENED) {
        sfRenderWindow_drawRectangleShape(graphic->window, dropdown->bg, NULL);
        for (node_t *node = dropdown->buttons->head; node; node = node->next)
            draw_dropdown_button(graphic, node->data);
    }
}

void draw_dropdown_button(graphic_t *graphic, button_t *button)
{
    sfRenderWindow_drawSprite(graphic->window, button->sprite, NULL);
    if (button->text)
        sfRenderWindow_drawText(graphic->window, button->text->text, NULL);
}
