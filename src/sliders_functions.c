/*
** EPITECH PROJECT, 2023
** sliders_functions
** File description:
** file for sliders functions functions
*/

#include <malloc.h>
#include "sliders.h"
#include "textures.h"

void slider_set_values(graphic_t *graphic, slider_t *slider,
                        slider_constructor_t constructor)
{
    sfSprite_setTexture(slider->bar, get_texture(graphic, constructor.bar)
                ->texture, sfTrue);
    sfSprite_setTexture(slider->scroller, get_texture(graphic,
                constructor.scroller)->texture, sfTrue);
    sfSprite_setPosition(slider->bar, constructor.pos);
    sfSprite_setPosition(slider->scroller, constructor.pos);
    sfFloatRect bar_rect = sfSprite_getGlobalBounds(slider->bar);
    sfSprite_setScale(slider->bar, (sfVector2f) {constructor.size.x /
                bar_rect.width,constructor.size.y / bar_rect.height});
}

void destroy_slider_list(list_t *list)
{
    for (node_t *node = list->head; node; node = node->next)
        destroy_slider((slider_t *) node->data);
    list_free(list, false);
}

void destroy_slider(slider_t *slider)
{
    sfSprite_destroy(slider->bar);
    sfSprite_destroy(slider->scroller);
    free(slider);
}

void cond_click_slider(graphic_t *graphic, sfMouseButtonEvent mouse,
                        slider_t *slider)
{
    sfFloatRect slider_rect = sfSprite_getGlobalBounds(slider->scroller);
    sfFloatRect bar_rect = sfSprite_getGlobalBounds(slider->bar);
    if (sfFloatRect_contains(&slider_rect, (float) mouse.x, (float) mouse.y)) {
        if (slider->on_click)
            slider->on_click(graphic, slider, mouse);
        slider->is_clicked = true;
    } else if (sfFloatRect_contains(&bar_rect, mouse.x, mouse.y))
        slider_bar_click(graphic, slider, mouse);
}

void draw_slider(graphic_t *graphic, slider_t *slider)
{
    sfRenderWindow_drawSprite(graphic->window, slider->bar, NULL);
    sfRenderWindow_drawSprite(graphic->window, slider->scroller, NULL);
}
