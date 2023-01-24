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

button_t * build_button(graphic_t * graphic, int texture_id,
                        sfVector2f position, int scene)
{
    button_t * button = malloc(sizeof(button_t));

    button->sprite = sfSprite_create();
    sfSprite_setPosition(button->sprite, position);
    button->text = NULL;

    button->layer = 0;
    button->scene = scene;
    button->id = list_size(graphic->buttons);
    button->on_click = NULL;
    button->on_hover = NULL;
    button->on_release = NULL;

    button->rect = sfSprite_getGlobalBounds(button->sprite);
    sfSprite_setTexture(button->sprite,
                        get_texture(graphic, texture_id)->texture, sfTrue);
    list_append(graphic->buttons, button);
    return button;
}

void destroy_button(button_t * button)
{
    sfSprite_destroy(button->sprite);
    free(button);
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

void draw_buttons(graphic_t * graphic)
{
    for (node_t * buttons = graphic->buttons->head; buttons;
                        buttons = buttons->next) {
        button_t * button = buttons->data;
        sfRenderWindow_drawSprite(graphic->window, button->sprite, NULL);
    }
}
