/*
** EPITECH PROJECT, 2022
** main
** File description:
** main file for test_lib
*/

#include <stdio.h>
#include <stdlib.h>

#include "graphic.h"
#include "actors.h"
#include "buttons.h"
#include "texts.h"
#include "fonts.h"
#include "textures.h"

void init_function(struct graphic *);
void update_function(struct graphic *);
void button_click(graphic_t *, button_t *, sfMouseButton);

int main(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow * window = sfRenderWindow_create(mode, "TEST GAME",
                                sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);

    graphic_t * game = build_game(window);
    game->init = &init_function;
    game->update = &update_function;

    init_game(game);
    return 0;
}

void init_function(graphic_t * graphic)
{
    build_texture(graphic, "test_lib/earth.png");
    build_texture(graphic, "test_lib/button.png");

    actor_t * earth = build_actor(graphic, 0, (sfVector2f) {50, 50}, 0);
    earth->animation = build_animation((sfIntRect) {0, 0, 300, 300},
        (sfVector2i){15000, 300}, (sfVector2i){0, 0}, 10);

    build_font(graphic, "test_lib/monogram.ttf");
    text_t * text = build_text(graphic, "BUTTON", 0, 20);
    button_t * button = build_button(graphic, 1, (sfVector2f){100, 100}, 0);
    button->text = text;
    button->on_click = &button_click;
}

void button_click(graphic_t * graphic, button_t * button, sfMouseButton mouse)
{
    if (mouse == sfMouseLeft)
        printf("Button clicked\n");
    sfSprite_setPosition(button->sprite,
                        (sfVector2f){rand() % 750, rand() % 550});
    sfSprite_setScale(button->sprite,
                        (sfVector2f){1 + rand() % 4, 1 + rand() % 4});
}

void update_function(graphic_t * graphic)
{
    actor_t * earth = get_actor(graphic, 0);
    sfSprite_move(earth->sprite, (sfVector2f){1, 1});
    sfVector2f pos = sfSprite_getPosition(earth->sprite);

    if (pos.x > 800)
        sfSprite_setPosition(earth->sprite, (sfVector2f){0, pos.y});
    if (pos.y > 600)
        sfSprite_setPosition(earth->sprite, (sfVector2f){pos.x, 0});
}
