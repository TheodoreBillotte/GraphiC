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

button_t * build_button(graphic_t * graphic, button_constructor_t constructor)
{
    button_t *button = malloc(sizeof(button_t));

    *button = (button_t) {0};
    button->sprite = sfSprite_create();
    button->scene = constructor.scene;
    button->layer = constructor.layer;
    button->id = graphic->ids->button_id++;
    button->user_data = constructor.user_data;
    sfSprite_setTexture(button->sprite, get_texture(graphic,
                        constructor.texture)->texture, sfTrue);
    sfSprite_setPosition(button->sprite, constructor.pos);
    sfSprite_setScale(button->sprite, constructor.size);
    button->rect = sfSprite_getGlobalBounds(button->sprite);
    if (constructor.scene != -1)
        list_append(get_scene_drawable(graphic, button->scene, button->layer)
                    .buttons, button);
    else
        list_append(graphic->ui_layers[button->layer].buttons, button);
    return button;
}

void destroy_button(button_t *button)
{
    if (button->on_destroy)
        button->on_destroy(button);
    sfSprite_destroy(button->sprite);
    free(button);
}

void destroy_button_list(list_t *list)
{
    node_t *node = list->head;

    for (; node; node = node->next)
        destroy_button(node->data);
    list_free(list, false);
}

void update_button(button_t *button)
{
    text_t *text = button->text;
    if (!text)
        return;
    sfFloatRect text_rect = sfText_getGlobalBounds(text->text);
    sfFloatRect button_rect = sfSprite_getGlobalBounds(button->sprite);

    button->rect = button_rect;
    sfText_setPosition(text->text, (sfVector2f) {
        button_rect.left + (button_rect.width - text_rect.width) / 2,
        button_rect.top + (button_rect.height - text_rect.height * 1.5F) / 2
    });
}
