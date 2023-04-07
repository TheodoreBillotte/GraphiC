/*
** EPITECH PROJECT, 2023
** drawables_functions
** File description:
** file for drawables functions
*/

#include "graphic.h"
#include "drawables.h"
#include "dropdown.h"
#include "text_inputs.h"
#include "dialog.h"
#include "sliders.h"

void draw_others(graphic_t *graphic, int layer)
{
    for (node_t *list = get_drawable(graphic, layer).sliders->head; list;
                list = list->next)
        draw_slider(graphic, (slider_t *) list->data);
    for (node_t *list = get_drawable(graphic, layer).dropdowns->head; list;
                list = list->next)
        draw_dropdown(graphic, (dropdown_t *) list->data);
    for (node_t *list = get_drawable(graphic, layer).text_inputs->head; list;
                list = list->next)
        draw_text_input(graphic, (text_input_t *) list->data);
    for (node_t *list = get_drawable(graphic, layer).dialogs->head; list;
                list = list->next)
        draw_dialog(graphic, (dialog_t *) list->data);
}
