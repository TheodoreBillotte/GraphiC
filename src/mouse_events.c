/*
** EPITECH PROJECT, 2023
** events_functions
** File description:
** file for mouse events functions
*/

#include "events.h"
#include "drawables.h"
#include "sliders.h"

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

void cond_click_button(graphic_t *graphic, sfMouseButtonEvent mouse,
                        button_t *button)
{
    if (button->on_click && sfFloatRect_contains(&button->rect, (float)
        mouse.x, (float) mouse.y))
        button->on_click(graphic, button, mouse.button);
}

void cond_click_slider(graphic_t *graphic, sfMouseButtonEvent mouse,
                        slider_t *slider)
{
    sfFloatRect slider_rect = sfSprite_getGlobalBounds(slider->scroller);
    sfFloatRect bar_rect = sfSprite_getGlobalBounds(slider->bar);
    if (sfFloatRect_contains(&slider_rect, (float) mouse.x, (float) mouse.y)) {
        if (slider->on_click)
            slider->on_click(graphic, slider, mouse);
        slider->is_clicked = true;
    } else if (sfFloatRect_contains(&bar_rect, mouse.x, mouse.y))
        slider_bar_click(graphic, slider, mouse);
}

void play_button(graphic_t * graphic, sfMouseButtonEvent mouse)
{
    for (int layer = 0; layer < graphic->nb_layers; layer++) {
        for (node_t * buttons = graphic->drawables[graphic->scene][layer]
            .buttons->head; buttons; buttons = buttons->next) {
            button_t * button = (button_t *) buttons->data;
            cond_click_button(graphic, mouse, button);
        }
    }
    for (int layer = 0; layer < graphic->nb_layers; layer++) {
        for (node_t * sliders = get_drawable(graphic, layer).sliders->head;
            sliders; sliders = sliders->next) {
            slider_t * slider = (slider_t *) sliders->data;
            cond_click_slider(graphic, mouse, slider);
        }
    }
}
