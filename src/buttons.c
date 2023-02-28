/*
** EPITECH PROJECT, 2022
** buttons
** File description:
** file for buttons functions
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "buttons.h"
#include "graphic.h"
#include "textures.h"
#include "drawables.h"

button_t * build_button(graphic_t * graphic, int texture_id,
                        int scene, int layer)
{
    button_t * button = malloc(sizeof(button_t));

    button->sprite = sfSprite_create();
    button->text = NULL;

    button->scene = scene;
    button->id = graphic->ids->button_id++;
    button->on_click = NULL;
    button->on_hover = NULL;
    button->on_release = NULL;
    button->on_leave = NULL;
    button->on_enter = NULL;

    button->rect = sfSprite_getGlobalBounds(button->sprite);
    sfSprite_setTexture(button->sprite,
                        get_texture(graphic, texture_id)->texture, sfTrue);
    list_append(get_scene_drawable(graphic, scene, layer).buttons, button);
    return button;
}

void destroy_button(button_t * button)
{
    sfSprite_destroy(button->sprite);
    free(button);
}

void destroy_button_list(list_t * list)
{
    node_t * node = list->head;

    for (; node; node = node->next)
        destroy_button(node->data);
    list_free(list, false);
}

void update_button(button_t * button)
{
    text_t * text = button->text;
    sfFloatRect rect = sfText_getGlobalBounds(text->text);
    sfFloatRect b_rect = sfSprite_getGlobalBounds(button->sprite);
    button->rect = b_rect;
    sfText_setPosition(text->text, (sfVector2f) {
        b_rect.left + (b_rect.width - rect.width) / 2,
        b_rect.top + (b_rect.height - rect.height) / 2
    });
}
