/*
** EPITECH PROJECT, 2023
** events_functions
** File description:
** file for mouse events functions
*/

#include "events.h"
#include "drawables.h"
#include "sliders.h"
#include "dropdown.h"

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
        for (node_t *buttons = get_drawable(graphic, layer).buttons->head;
            buttons; buttons = buttons->next) {
            button_t *button = (button_t *) buttons->data;
            cond_hover(graphic, mouse_pos, button);
        }
        for (node_t *dropdowns = get_drawable(graphic, layer).dropdowns->head;
             dropdowns; dropdowns = dropdowns->next) {
            dropdown_t *dropdown = (dropdown_t *) dropdowns->data;
            cond_dropdown_hover(graphic, mouse_pos, dropdown);
        }
    }
    check_exit(graphic, mouse_pos);
}

void play_button(graphic_t * graphic, sfMouseButtonEvent mouse)
{
    for (int layer = 0; layer < graphic->nb_layers; layer++) {
        for (node_t *buttons = graphic->drawables[graphic->scene][layer]
            .buttons->head; buttons; buttons = buttons->next) {
            button_t *button = (button_t *) buttons->data;
            cond_click_button(graphic, mouse, button);
        }
        for (node_t *sliders = get_drawable(graphic, layer).sliders->head;
             sliders; sliders = sliders->next) {
            slider_t *slider = (slider_t *) sliders->data;
            cond_click_slider(graphic, mouse, slider);
        }
        for (node_t *dropdowns = get_drawable(graphic, layer).dropdowns->head;
             dropdowns; dropdowns = dropdowns->next) {
            dropdown_t *dropdown = (dropdown_t *) dropdowns->data;
            cond_click_dropdown(graphic, dropdown, mouse);
        }
    }
}
