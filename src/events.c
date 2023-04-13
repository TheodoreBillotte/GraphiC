/*
** EPITECH PROJECT, 2022
** events
** File description:
** file for events functions
*/

#include "events.h"
#include "sliders.h"
#include "drawables.h"
#include "dropdown.h"
#include "text_inputs.h"
#include "layer_options.h"

void play_events(graphic_t * graphic)
{
    sfEvent event;
    graphic->mouse_pos = get_mouse_pos(graphic->window);
    check_hover(graphic);
    while (sfRenderWindow_pollEvent(graphic->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(graphic->window);
        if (event.type == sfEvtMouseButtonPressed)
            play_button(graphic, event.mouseButton);
        if (event.type == sfEvtMouseButtonReleased)
            release_button(graphic, event.mouseButton);
        if (event.type == sfEvtTextEntered)
            play_key_pressed(graphic, event.text);
        if (graphic->event != NULL)
            graphic->event(graphic, &event);
    }
}

void release_button(graphic_t *graphic, sfMouseButtonEvent mouse)
{
    mouse.x = graphic->mouse_pos.x;
    mouse.y = graphic->mouse_pos.y;
    for (int layer = 0; layer < graphic->nb_layers; layer++) {
        if (!GET_LAYER_OPTION(graphic, layer, 1)) continue;
        for (node_t *buttons = get_drawable(graphic, layer).buttons->head;
                buttons; buttons = buttons->next)
            check_release(graphic, mouse, buttons->data);
        for (node_t *sliders = get_drawable(graphic, layer).sliders->head;
                sliders; sliders = sliders->next)
            slider_bar_release(graphic, sliders->data, mouse);
        for (node_t *dropdowns = get_drawable(graphic, layer).dropdowns->head;
                dropdowns; dropdowns = dropdowns->next)
            cond_dropdown_release(graphic, dropdowns->data, mouse);
        for (node_t *text_inputs = get_drawable(graphic, layer).
                text_inputs->head; text_inputs; text_inputs = text_inputs->next)
            text_input_release(graphic, text_inputs->data, mouse);
    }
    ui_release_button(graphic, mouse);
}

void ui_release_button(graphic_t *graphic, sfMouseButtonEvent mouse)
{
    for (int layer = 0; layer < graphic->nb_layers; layer++) {
        if (!GET_UI_LAYER_OPTION(graphic, layer, 1))
            continue;
        for (node_t *buttons = graphic->ui_layers[layer].buttons->head;
                buttons; buttons = buttons->next)
            check_release(graphic, mouse, buttons->data);
        for (node_t *sliders = graphic->ui_layers[layer].sliders->head;
                sliders; sliders = sliders->next)
            slider_bar_release(graphic, sliders->data, mouse);
        for (node_t *dropdowns = graphic->ui_layers[layer].dropdowns->head;
                dropdowns; dropdowns = dropdowns->next)
            cond_dropdown_release(graphic, dropdowns->data, mouse);
        for (node_t *text_inputs = graphic->ui_layers[layer].
                text_inputs->head; text_inputs; text_inputs = text_inputs->next)
            text_input_release(graphic, text_inputs->data, mouse);
    }
}

void check_release(graphic_t *graphic, sfMouseButtonEvent mouse,
                    button_t *button)
{
    if (button->on_release && sfFloatRect_contains(&button->rect,
                                (float) mouse.x, (float) mouse.y))
        button->on_release(graphic, button, mouse);
}

void check_enter(graphic_t *graphic, button_t *button)
{
    if (!list_contains(graphic->hover_buttons, button)) {
        if (button->on_enter)
            button->on_enter(graphic, button);
        list_append(graphic->hover_buttons, button);
    }
}
