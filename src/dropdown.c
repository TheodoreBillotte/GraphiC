/*
** EPITECH PROJECT, 2023
** dropdown
** File description:
** file for dropdown functions
*/

#include <malloc.h>
#include "dropdown.h"
#include "buttons.h"
#include "drawables.h"

dropdown_t *build_dropdown(graphic_t * graphic,
                        dropdown_constructor_t constructor)
{
    dropdown_t *dropdown = malloc(sizeof(dropdown_t));
    dropdown->id = graphic->ids->dropdown_id++;
    dropdown->text = constructor.text;
    dropdown->on_click = NULL;
    dropdown->on_hover = NULL;
    dropdown->on_release = NULL;
    dropdown->layer = constructor.layer;
    dropdown->scene = constructor.scene;
    dropdown->sprite = sfSprite_create();
    dropdown->state = CLOSED;
    sfSprite_setTexture(dropdown->sprite, get_texture(graphic,
                        constructor.texture)->texture, sfFalse);
    sfSprite_setPosition(dropdown->sprite, constructor.pos);
    dropdown->bg = sfRectangleShape_create();
    dropdown->extend_side = constructor.extend_side;
    sfRectangleShape_setSize(dropdown->bg, (sfVector2f){constructor.width, 0});
    sfRectangleShape_setFillColor(dropdown->bg, constructor.bg_color);
    dropdown->buttons = create_list();
    list_append(get_drawable(graphic, dropdown->layer).dropdowns, dropdown);
    return dropdown;
}

button_t *dropdown_add_button(graphic_t *graphic, dropdown_t *dropdown,
                                int texture_id)
{
    button_t *button = malloc(sizeof(button_t));

    *button = (button_t) {0};
    button->sprite = sfSprite_create();
    button->id = list_size(dropdown->buttons);
    sfSprite_setTexture(button->sprite,
        get_texture(graphic, texture_id)->texture, sfTrue);
    setup_new_button(dropdown, button);
    button->rect = sfSprite_getGlobalBounds(button->sprite);
    list_append(dropdown->buttons, button);
    return button;
}

void setup_new_button(dropdown_t *dropdown, button_t *button)
{
    sfFloatRect rect;
    sfVector2f pos = sfSprite_getPosition(dropdown->sprite);
    node_t *last_button = dropdown->buttons->tail;
    sfVector2f bg = sfRectangleShape_getPosition(dropdown->bg);

    if (bg.x == 0 && bg.y == 0)
        change_bg_pos(dropdown);
    bg = sfRectangleShape_getPosition(dropdown->bg);
    if (last_button) {
        sfFloatRect bt = sfSprite_getGlobalBounds(((button_t *)
                last_button->data)->sprite);
        pos.y = bt.top + bt.height;
    } else
        pos.y = bg.y;
    pos.x = bg.x;
    rect = sfSprite_getGlobalBounds(button->sprite);
    sfVector2f size = sfRectangleShape_getSize(dropdown->bg);
    sfRectangleShape_setSize(dropdown->bg, (sfVector2f)
    {size.x, size.y + rect.height});
    sfSprite_setPosition(button->sprite, pos);
}

void destroy_dropdown(dropdown_t *dropdown)
{
    sfSprite_destroy(dropdown->sprite);
    sfRectangleShape_destroy(dropdown->bg);
    destroy_button_list(dropdown->buttons);
    free(dropdown);
}

void destroy_dropdown_list(list_t *dropdowns)
{
    for (node_t *node = dropdowns->head; node; node = node->next)
        destroy_dropdown(node->data);
    list_free(dropdowns, false);
}
