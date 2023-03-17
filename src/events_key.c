/*
** EPITECH PROJECT, 2023
** events_key
** File description:
** file for events key functions
*/

#include "events.h"
#include "drawables.h"
#include "text_inputs.h"

void play_key_pressed(graphic_t *graphic, sfTextEvent event)
{
    for (int layer = 0; layer < graphic->nb_layers; layer++) {
        for (node_t *text_inputs = get_drawable(graphic, layer).
            text_inputs->head; text_inputs; text_inputs = text_inputs->next) {
            text_input_t *text_input = (text_input_t *) text_inputs->data;
            text_input_key_pressed(graphic, text_input, event);
        }
    }
}
