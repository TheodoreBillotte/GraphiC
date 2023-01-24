/*
** EPITECH PROJECT, 2022
** graphic
** File description:
** main file for GraphiC library
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>

#include "graphic.h"
#include "animations.h"
#include "sounds.h"
#include "musics.h"
#include "buttons.h"
#include "events.h"
#include "fonts.h"
#include "texts.h"
#include "textures.h"

graphic_t * build_game(sfRenderWindow * window)
{
    graphic_t * game = malloc(sizeof(graphic_t));
    game->window = window;
    game->view = sfView_create();
    game->game_clock = sfClock_create();
    game->sprite_id = 0;
    game->scene = 0;

    game->textures = create_list();
    game->actors = create_list();
    game->sounds = create_list();
    game->musics = create_list();
    game->buttons = create_list();
    game->fonts = create_list();
    game->texts = create_list();
    game->init = NULL;
    game->update = NULL;
    game->close = NULL;
    game->draw = NULL;
    game->event = NULL;
    return game;
}

void init_game(graphic_t * game)
{
    if (game->init != NULL)
        game->init(game);

    while (sfRenderWindow_isOpen(game->window)) {
        play_events(game);
        sfRenderWindow_clear(game->window, sfBlack);
        if (game->update != NULL)
            game->update(game);
        game_update(game);
        if (game->draw != NULL)
            game->draw(game);
        draw_actors(game);
        draw_buttons(game);
        draw_texts(game);
        sfRenderWindow_display(game->window);
    }
    if (game->close != NULL)
        game->close(game);
    destroy_game(game);
}

void game_update(graphic_t * graphic)
{
    for (node_t * actors = graphic->actors->head; actors;
                        actors = actors->next) {
        actor_t * actor = (actor_t *) actors->data;
        if (actor->scene == graphic->scene)
            update_actor(actor);
    }

    for (node_t * buttons = graphic->buttons->head; buttons;
                        buttons = buttons->next) {
        button_t * button = (button_t *) buttons->data;
        if (button->scene == graphic->scene)
            update_button(button);
    }
}

void destroy_lists(graphic_t * game)
{
    for (node_t * actor = game->actors->head; actor; actor = actor->next)
        destroy_actor(actor->data);
    for (node_t * t = game->textures->head; t; t = t->next)
        destroy_texture(t->data);
    for (node_t * button = game->buttons->head; button; button = button->next)
        destroy_button(button->data);
    for (node_t * sound = game->sounds->head; sound; sound = sound->next)
        destroy_sound(sound->data);
    for (node_t * music = game->musics->head; music; music = music->next)
        destroy_music(music->data);
    for (node_t * font = game->fonts->head; font; font = font->next)
        destroy_font(font->data);
    for (node_t * text = game->texts->head; text; text = text->next)
        destroy_text(text->data);
}

void destroy_game(graphic_t * game)
{
    destroy_lists(game);
    list_free(game->textures, false);
    list_free(game->actors, false);
    list_free(game->sounds, false);
    list_free(game->musics, false);
    list_free(game->buttons, false);
    list_free(game->fonts, false);
    sfRenderWindow_destroy(game->window);
    sfClock_destroy(game->game_clock);
}
