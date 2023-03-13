/*
** EPITECH PROJECT, 2023
** layers
** File description:
** file for layers functions
*/

#include "layers.h"
#include "list.h"
#include "drawables.h"

void set_actor_layer(graphic_t *graphic, actor_t *actor, int layer)
{
    list_t *list = get_scene_drawable
        (graphic, actor->scene, actor->layer).actors;
    node_t *node = list_get_node_by_data(list, actor);

    if (layer < 0 || layer >= graphic->nb_layers)
        return;
    if (node->prev)
        node->prev->next = node->next;
    else
        list->head = node->next;
    if (node->next)
        node->next->prev = node->prev;
    else
        list->tail = node->prev;
    actor->layer = layer;
    list_append_node(get_scene_drawable(graphic,actor->scene, layer).actors,
                                                                    node);
}

void set_button_layer(graphic_t *graphic, actor_t *button, int layer)
{
    list_t *list = get_scene_drawable
        (graphic, button->scene, button->layer).buttons;
    node_t *node = list_get_node_by_data(list, button);

    if (layer < 0 || layer >= graphic->nb_layers)
        return;
    if (node->prev)
        node->prev->next = node->next;
    else
        list->head = node->next;
    if (node->next)
        node->next->prev = node->prev;
    else
        list->tail = node->prev;
    button->layer = layer;
    list_append_node(get_scene_drawable(graphic, button->scene, layer).buttons,
                                                                    node);
}

void set_text_layer(graphic_t *graphic, actor_t *text, int layer)
{
    list_t *list = get_scene_drawable
        (graphic, text->scene, text->layer).texts;
    node_t *node = list_get_node_by_data(list, text);

    if (layer < 0 || layer >= graphic->nb_layers)
        return;
    if (node->prev)
        node->prev->next = node->next;
    else
        list->head = node->next;
    if (node->next)
        node->next->prev = node->prev;
    else
        list->tail = node->prev;
    text->layer = layer;
    list_append_node(get_scene_drawable(graphic, text->scene, layer).texts,
                                                                    node);
}
