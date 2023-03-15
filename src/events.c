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

void play_events(graphic_t * graphic)
{
    sfEvent event;
    check_hover(graphic);
    while (sfRenderWindow_pollEvent(graphic->window, &event)) {
        if (event.type == sfEvtResized) {
            sfView_destroy(graphic->view);
            graphic->view = sfView_createFromRect((sfFloatRect) {0, 0,
                event.size.width, event.size.height});
            sfRenderWindow_setView(graphic->window, graphic->view);
        }
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(graphic->window);
        if (event.type == sfEvtMouseButtonPressed)
            play_button(graphic, event.mouseButton);
        if (event.type == sfEvtMouseButtonReleased)
            release_button(graphic, event.mouseButton);
        if (graphic->event != NULL)
            graphic->event(graphic, &event);
    }
}

void release_button(graphic_t *graphic, sfMouseButtonEvent mouse)
{
    for (int layer = 0; layer < graphic->nb_layers; layer++) {
        for (node_t *buttons = get_drawable(graphic, layer).buttons->head;
                buttons; buttons = buttons->next)
            check_release(graphic, mouse, buttons->data);
        for (node_t *sliders = get_drawable(graphic, layer).sliders->head;
                sliders; sliders = sliders->next)
            slider_bar_release(graphic, sliders->data, mouse);
        for (node_t *dropdowns = get_drawable(graphic, layer).dropdowns->head;
                dropdowns; dropdowns = dropdowns->next)
            cond_dropdown_release(graphic, dropdowns->data, mouse);
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
    if (button->on_enter && !list_contains(graphic->hover_buttons, button)) {
        button->on_enter(graphic, button);
        list_append(graphic->hover_buttons, button);
    }
}

void check_exit(graphic_t *graphic, sfVector2i mouse)
{
    node_t *buttons = graphic->hover_buttons->head;

    if (graphic->hover_buttons->head == NULL)
        return;
    while (buttons) {
        button_t *button = (button_t *) buttons->data;
        if (button->on_leave && !sfFloatRect_contains(&button->rect,
                                (float) mouse.x, (float) mouse.y)) {
            button->on_leave(graphic, button);
            buttons = buttons->prev;
            list_remove_data(graphic->hover_buttons, button, false);
        }
        if (buttons)
            buttons = buttons->next;
    }
}
