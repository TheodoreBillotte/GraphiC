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
    slider->on_click = NULL;
    slider->on_release = NULL;
    slider->is_clicked = false;
    slider_set_values(graphic, slider, constructor);
    if (constructor.scene != -1)
        list_append(get_scene_drawable(graphic, constructor.scene,
                constructor.layer).sliders, slider);
    else
        list_append(graphic->ui_layers[constructor.layer].sliders, slider);
    return slider;
}

void update_slider(graphic_t *graphic, slider_t *slider)
{
    sfVector2f pos = sfSprite_getPosition(slider->scroller);
    sfVector2f mouse_pos = graphic->mouse_pos;
    sfFloatRect bar = sfSprite_getGlobalBounds(slider->bar);

    if (!slider->is_clicked)
        return;
    pos.x = mouse_pos.x < bar.left ? bar.left : mouse_pos.x > bar.left +
            bar.width ? bar.left + bar.width : mouse_pos.x;
    slider->value = slider->min_value + (slider->max_value -
            slider->min_value) * (pos.x - bar.left) / bar.width;
    sfSprite_setPosition(slider->scroller, pos);
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
    if (slider->is_clicked ||
            sfFloatRect_contains(&rect, mouse.x, mouse.y))
        if (slider->on_release)
            slider->on_release(graphic, slider, mouse);
    slider->is_clicked = false;
}
