/*
** EPITECH PROJECT, 2023
** scenes
** File description:
** file for scenes functions
*/

#include "scenes.h"
#include "list.h"
#include "drawables.h"

void set_actor_scene(graphic_t *graphic, actor_t *actor, int scene)
{
    list_t *list = get_scene_drawable
        (graphic, actor->scene, actor->layer).actors;
    node_t *node = list_get_node_by_data(list, actor);

    if (scene < 0 || scene >= graphic->nb_scenes)
        return;
    if (node->prev)
        node->prev->next = node->next;
    else
        list->head = node->next;
    if (node->next)
        node->next->prev = node->prev;
    else
        list->tail = node->prev;
    actor->scene = scene;
    list_append_node(get_scene_drawable(graphic, scene, actor->layer).actors,
                                                                    node);
}

void set_button_scene(graphic_t *graphic, actor_t *button, int scene)
{
    list_t *list = get_scene_drawable
        (graphic, button->scene, button->layer).buttons;
    node_t *node = list_get_node_by_data(list, button);

    if (scene < 0 || scene >= graphic->nb_scenes)
        return;
    if (node->prev)
        node->prev->next = node->next;
    else
        list->head = node->next;
    if (node->next)
        node->next->prev = node->prev;
    else
        list->tail = node->prev;
    button->scene = scene;
    list_append_node(get_scene_drawable(graphic, scene, button->layer).buttons,
                                                                    node);
}

void set_text_scene(graphic_t *graphic, actor_t *text, int scene)
{
    list_t *list = get_scene_drawable
        (graphic, text->scene, text->layer).texts;
    node_t *node = list_get_node_by_data(list, text);

    if (scene < 0 || scene >= graphic->nb_scenes)
        return;
    if (node->prev)
        node->prev->next = node->next;
    else
        list->head = node->next;
    if (node->next)
        node->next->prev = node->prev;
    else
        list->tail = node->prev;
    text->scene = scene;
    list_append_node(get_scene_drawable(graphic, scene, text->layer).texts,
                                                                    node);
}
