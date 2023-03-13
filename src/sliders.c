/*
** EPITECH PROJECT, 2023
** slider
** File description:
** file for slider functions
*/

#include <malloc.h>

#include "sliders.h"
#include "drawables.h"

slider_t *build_slider(graphic_t *graphic, slider_constructor_t constructor)
{
    slider_t *slider = malloc(sizeof(slider_t));
    slider->bar = sfSprite_create();
    slider->scroller = sfSprite_create();
    slider->value = constructor.min_value;
    slider->min_value = constructor.min_value;
    slider->max_value = constructor.max_value;
    slider->layer = constructor.layer;
    slider->scene = constructor.scene;
    slider->id = graphic->ids->slider_id++;
    sfSprite_setTexture(slider->bar, constructor.bar, sfTrue);
    sfSprite_setTexture(slider->scroller, constructor.scroller, sfTrue);
    sfSprite_setPosition(slider->bar, constructor.pos);
    sfSprite_setPosition(slider->scroller, constructor.pos);
    sfFloatRect bar_rect = sfSprite_getGlobalBounds(slider->bar);
    sfSprite_setScale(slider->bar, (sfVector2f) {constructor.size.x /
                bar_rect.width,constructor.size.y / bar_rect.height});
    list_append(get_drawable(graphic, constructor.layer).sliders, slider);
    slider->on_click = NULL;
    slider->on_release = NULL;
    return slider;
}

void update_slider(graphic_t *graphic, slider_t *slider)
{
    sfVector2f pos = sfSprite_getPosition(slider->scroller);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(graphic->window);
    sfFloatRect bar = sfSprite_getGlobalBounds(slider->bar);

    if (!slider->is_clicked)
        return;
    pos.x = mouse_pos.x < bar.left ? bar.left : mouse_pos.x > bar.left +
            bar.width ? bar.left + bar.width : mouse_pos.x;
    slider->value = slider->min_value + (slider->max_value -
            slider->min_value) * (pos.x - bar.left) / bar.width;
    sfSprite_setPosition(slider->scroller, pos);
}

void update_sliders(graphic_t *graphic)
{
    for (int layer = 0; layer < graphic->nb_layers; layer++)
        for (node_t *list = get_drawable(graphic, layer).sliders->head; list;
                    list = list->next)
            update_slider(graphic, list->data);
}

void slider_bar_click(graphic_t *graphic, slider_t *slider,
                        sfMouseButtonEvent mouse)
{
    sfFloatRect bar_rect = sfSprite_getGlobalBounds(slider->bar);
    sfVector2f pos = sfSprite_getPosition(slider->scroller);

    if (slider->on_click)
        slider->on_click(graphic, slider, mouse);
    pos.x = (float) mouse.x;
    slider->value = slider->min_value + (slider->max_value -
            slider->min_value) * (pos.x - bar_rect.left) / bar_rect.width;
    sfSprite_setPosition(slider->scroller, pos);
}

void slider_bar_release(graphic_t *graphic, slider_t *slider,
                        sfMouseButtonEvent mouse)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(slider->bar);
    if ((slider->is_clicked && slider->on_release) ||
            sfFloatRect_contains(&rect, mouse.x, mouse.y))
        slider->on_release(graphic, slider, mouse);
    slider->is_clicked = false;
}
