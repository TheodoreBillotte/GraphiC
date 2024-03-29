/*
** EPITECH PROJECT, 2022
** buttons_functions
** File description:
** file for buttons functions
*/

#include <SFML/Graphics.h>

#include "buttons.h"
#include "drawables.h"

button_t *get_button_list(list_t *list, int id)
{
    node_t *buttons = list->head;

    for (button_t * button = (button_t *) buttons->data; buttons; buttons =
                                                        buttons->next) {
        if (button->id == id)
            return button;
    }
    return NULL;
}

button_t *button_loop(graphic_t *graphic, int scene, int id)
{
    for (int layer = 0; layer < graphic->nb_layers; layer++) {
        button_t * button = get_button_list(
            get_scene_drawable(graphic, scene, layer).buttons, id);
        if (button)
            return button;
    }
    return NULL;
}

button_t *get_button(graphic_t * graphic, int id)
{
    for (int scene = 0; scene < graphic->nb_scenes; scene++) {
        button_t * button = button_loop(graphic, scene, id);
        if (button)
            return button;
    }
    return NULL;
}

void cond_click_button(graphic_t *graphic, sfMouseButtonEvent mouse,
                        button_t *button)
{
    if (button->on_click && sfFloatRect_contains(&button->rect, (float)
            mouse.x, (float) mouse.y))
        button->on_click(graphic, button, mouse);
}

void draw_button(graphic_t *graphic, button_t *button)
{
    if (button->on_draw)
        button->on_draw(graphic, button);
    sfRenderWindow_drawSprite(graphic->window, button->sprite, NULL);
}
