/*
** EPITECH PROJECT, 2022
** events
** File description:
** file for events functions
*/

#include <SFML/Window/Event.h>
#include "graphic.h"
#include "events.h"

void play_events(graphic_t * graphic)
{
    sfEvent event;
    check_hover(graphic);
    while (sfRenderWindow_pollEvent(graphic->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(graphic->window);
        if (event.type == sfEvtMouseButtonPressed)
            play_button(graphic, event.mouseButton);
        if (graphic->event != NULL)
            graphic->event(graphic, &event);
    }
}

void check_hover(graphic_t * graphic)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(graphic->window);

    for (node_t * buttons = graphic->buttons->head; buttons; buttons =
                                                            buttons->next) {
        button_t * button = (button_t *) buttons->data;
        if (button->on_hover && sfFloatRect_contains(&button->rect,
                                (float) mouse_pos.x, (float) mouse_pos.y))
            button->on_hover(graphic, button);
    }
}

void play_button(graphic_t * graphic, sfMouseButtonEvent mouse)
{
    for (node_t * buttons = graphic->buttons->head; buttons; buttons =
        buttons->next) {
        button_t * button = (button_t *) buttons->data;
        if (button->on_click && sfFloatRect_contains
                            (&button->rect, (float) mouse.x, (float) mouse.y))
            button->on_click(graphic, button, mouse.button);
    }
}
