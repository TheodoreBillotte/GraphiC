/*
** EPITECH PROJECT, 2023
** events_functions
** File description:
** file for mouse events functions
*/

#include "events.h"

void cond_hover(graphic_t *graphic, sfVector2i mouse_pos,
                        button_t *button)
{
    if (sfFloatRect_contains(&button->rect,
                (float) mouse_pos.x, (float) mouse_pos.y)) {
        check_enter(graphic, button);
        if (button->on_hover)
            button->on_hover(graphic, button);
    }
}

void check_hover(graphic_t * graphic)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(graphic->window);

    for (int layer = 0; layer < graphic->nb_layers; layer++) {
        for (node_t *buttons = graphic->drawables[graphic->scene][layer].buttons
            ->head; buttons; buttons = buttons->next) {
            button_t *button = (button_t *) buttons->data;
            cond_hover(graphic, mouse_pos, button);
        }
    }
    check_exit(graphic, mouse_pos);
}

void cond_click(graphic_t *graphic, sfMouseButtonEvent mouse,
                        button_t *button)
{
    if (button->on_click && sfFloatRect_contains(&button->rect, (float)
        mouse.x, (float) mouse.y))
        button->on_click(graphic, button, mouse.button);
}

void play_button(graphic_t * graphic, sfMouseButtonEvent mouse)
{
    for (int layer = 0; layer < graphic->nb_layers; layer++) {
        for (node_t * buttons = graphic->drawables[graphic->scene][layer]
            .buttons->head; buttons; buttons = buttons->next) {
            button_t * button = (button_t *) buttons->data;
            cond_click(graphic, mouse, button);
        }
    }
}
