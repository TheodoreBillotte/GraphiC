/*
** EPITECH PROJECT, 2022
** buttons_functions
** File description:
** file for buttons functions
*/

#include <SFML/Graphics.h>

#include "buttons.h"

button_t * get_button(graphic_t * graphic, int id)
{
    node_t * buttons = graphic->buttons->head;

    while (buttons) {
        button_t * button = (button_t *) buttons->data;
        if (button->id == id)
            return button;
        buttons = buttons->next;
    }
    return NULL;
}
