/*
** EPITECH PROJECT, 2023
** ui_layers
** File description:
** file for ui layers functions
*/

#include "ui_layers.h"
#include "layer_options.h"
#include "actors.h"
#include "buttons.h"
#include "texts.h"
#include "sliders.h"
#include "dropdown.h"
#include "text_inputs.h"
#include "dialog.h"
#include "tilemap.h"

drawables_t *build_ui_layers(graphic_t *graphic)
{
    drawables_t *ui_layers = malloc(sizeof(drawables_t) * graphic->nb_layers);

    for (int i = 0; i < graphic->nb_layers; i++) {
        ui_layers[i].actors = create_list();
        ui_layers[i].buttons = create_list();
        ui_layers[i].texts = create_list();
        ui_layers[i].sliders = create_list();
        ui_layers[i].dropdowns = create_list();
        ui_layers[i].text_inputs = create_list();
        ui_layers[i].dialogs = create_list();
        ui_layers[i].tilemaps = create_list();
    }
    return ui_layers;
}

void draw_ui_layers(graphic_t *graphic)
{
    for (int i = 0; i < graphic->nb_layers; i++) {
        drawables_t drawables = graphic->ui_layers[i];
        if (!GET_UI_LAYER_OPTION(graphic, i, 0))
            continue;
        for (node_t *list = drawables.actors->head; list; list = list->next)
            sfRenderWindow_drawSprite(graphic->window,
                ((actor_t *) list->data)->sprite, NULL);
        for (node_t *list = drawables.buttons->head; list; list = list->next)
            draw_button(graphic, (button_t *) list->data);
        for (node_t *list = drawables.texts->head; list; list = list->next)
            sfRenderWindow_drawText(graphic->window,
                ((text_t *) list->data)->text, NULL);
        draw_ui_layers_next(graphic, i);
    }
}

void draw_ui_layers_next(graphic_t *graphic, int layer)
{
    drawables_t drawables = graphic->ui_layers[layer];
    for (node_t *list = drawables.sliders->head; list; list = list->next)
        draw_slider(graphic, (slider_t *) list->data);
    for (node_t *list = drawables.dropdowns->head; list; list = list->next)
        draw_dropdown(graphic, (dropdown_t *) list->data);
    for (node_t *list = drawables.text_inputs->head; list; list = list->next)
        draw_text_input(graphic, (text_input_t *) list->data);
    for (node_t *list = drawables.dialogs->head; list; list = list->next)
        draw_dialog(graphic, (dialog_t *) list->data);
    for (node_t *list = drawables.tilemaps->head; list; list = list->next)
        draw_tilemap(graphic, list->data);
}

void destroy_ui_layers(graphic_t *graphic)
{
    for (int i = 0; i < graphic->nb_layers; i++) {
        destroy_actor_list(graphic->ui_layers[i].actors);
        destroy_button_list(graphic->ui_layers[i].buttons);
        destroy_text_list(graphic->ui_layers[i].texts);
        destroy_slider_list(graphic->ui_layers[i].sliders);
        destroy_dropdown_list(graphic->ui_layers[i].dropdowns);
        destroy_text_input_list(graphic->ui_layers[i].text_inputs);
        destroy_dialog_list(graphic->ui_layers[i].dialogs);
        destroy_tilemap_list(graphic->ui_layers[i].tilemaps);
    }
    free(graphic->ui_layers);
}

void update_ui_layers(graphic_t *graphic)
{
    for (int i = 0; i < graphic->nb_layers; i++) {
        if (!GET_UI_LAYER_OPTION(graphic, i, 1)) continue;
        drawables_t drawables = graphic->ui_layers[i];
        for (node_t *list = drawables.actors->head; list; list = list->next)
            update_actor(graphic, list->data);
        for (node_t *list = drawables.buttons->head; list; list = list->next)
            update_button(list->data);
        for (node_t *list = drawables.sliders->head; list; list = list->next)
            update_slider(graphic, list->data);
        for (node_t *list = drawables.dialogs->head; list; list = list->next)
            update_dialog(graphic, list->data);
    }
}
