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
#include "text_inputs.h"
#include "layer_options.h"

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
        if (!GET_LAYER_OPTION(graphic, layer, 1))
            continue;
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
    check_ui_hover(graphic);
    check_exit(graphic, mouse_pos);
}

void check_ui_hover(graphic_t * graphic)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(graphic->window);

    for (int layer = 0; layer < graphic->nb_layers; layer++) {
        if (!GET_UI_LAYER_OPTION(graphic, layer, 1))
            continue;
        for (node_t *buttons = graphic->ui_layers[layer].buttons->head;
            buttons; buttons = buttons->next) {
            button_t *button = (button_t *) buttons->data;
            cond_hover(graphic, mouse_pos, button);
        }
        for (node_t *dropdowns = graphic->ui_layers[layer].dropdowns->head;
            dropdowns; dropdowns = dropdowns->next) {
            dropdown_t *dropdown = (dropdown_t *) dropdowns->data;
            cond_dropdown_hover(graphic, mouse_pos, dropdown);
        }
    }
}

void play_button(graphic_t * graphic, sfMouseButtonEvent mouse)
{
    for (int layer = 0; layer < graphic->nb_layers; layer++) {
        if (!GET_LAYER_OPTION(graphic, layer, 1))
            continue;
        for (node_t *buttons = graphic->drawables[graphic->scene][layer]
            .buttons->head; buttons; buttons = buttons->next)
            cond_click_button(graphic, mouse, buttons->data);
        for (node_t *sliders = get_drawable(graphic, layer).sliders->head;
            sliders; sliders = sliders->next)
            cond_click_slider(graphic, mouse, sliders->data);
        for (node_t *dropdowns = get_drawable(graphic, layer).dropdowns->head;
            dropdowns; dropdowns = dropdowns->next)
            cond_click_dropdown(graphic, dropdowns->data, mouse);
        for (node_t *texts = get_drawable(graphic, layer).text_inputs->head;
            texts; texts = texts->next)
            text_input_click(graphic, texts->data, mouse);
    }
    play_ui_button(graphic, mouse);
}

void play_ui_button(graphic_t * graphic, sfMouseButtonEvent mouse)
{
    for (int layer = 0; layer < graphic->nb_layers; layer++) {
        if (!GET_UI_LAYER_OPTION(graphic, layer, 1))
            continue;
        for (node_t *buttons = graphic->ui_layers[layer].buttons->head;
            buttons; buttons = buttons->next)
            cond_click_button(graphic, mouse, buttons->data);
        for (node_t *sliders = graphic->ui_layers[layer].sliders->head;
            sliders; sliders = sliders->next)
            cond_click_slider(graphic, mouse, sliders->data);
        for (node_t *dropdowns = graphic->ui_layers[layer].dropdowns->head;
            dropdowns; dropdowns = dropdowns->next)
            cond_click_dropdown(graphic, dropdowns->data, mouse);
        for (node_t *texts = graphic->ui_layers[layer].text_inputs->head;
            texts; texts = texts->next)
            text_input_click(graphic, texts->data, mouse);
    }
}
