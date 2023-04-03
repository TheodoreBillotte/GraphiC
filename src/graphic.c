/*
** EPITECH PROJECT, 2022
** graphic
** File description:
** main file for GraphiC library
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <string.h>
#include "graphic.h"
#include "animations.h"
#include "sounds.h"
#include "musics.h"
#include "buttons.h"
#include "events.h"
#include "fonts.h"
#include "textures.h"
#include "drawables.h"
#include "ids.h"
#include "sliders.h"
#include "layer_options.h"

graphic_t * build_game(sfRenderWindow *window, int nb_scenes, int nb_layers)
{
    graphic_t * game = malloc(sizeof(graphic_t));

    *game = (graphic_t) {0};
    game->window = window;
    game->game_clock = sfClock_create();
    game->textures = create_list();
    game->sounds = create_list();
    game->musics = create_list();
    game->fonts = create_list();
    game->hover_buttons = create_list();
    game->nb_scenes = nb_scenes;
    game->nb_layers = nb_layers;
    game->drawables = create_drawables(nb_scenes, nb_layers);
    game->layers_options = build_layer_options(game);
    game->ids = build_ids();
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
        draw_game(game);
        sfRenderWindow_display(game->window);
    }
    if (game->close != NULL)
        game->close(game);
    destroy_game(game);
}

void game_update(graphic_t * graphic)
{
    for (int i = 0; i < graphic->nb_layers; i++) {
        if (!GET_LAYER_OPTION(graphic, i, 1))
            continue;
        drawables_t drawables = get_drawable(graphic, i);
        for (node_t * actors = drawables.actors->head; actors;
                            actors = actors->next) {
            actor_t * actor = (actor_t *) actors->data;
            update_actor(graphic, actor);
        }
        for (node_t * buttons = drawables.buttons->head; buttons;
                            buttons = buttons->next) {
            button_t * button = (button_t *) buttons->data;
            update_button(button);
        }
    }
    update_sliders(graphic);
}

void destroy_lists(graphic_t * game)
{
    for (node_t * t = game->textures->head; t; t = t->next)
        destroy_texture(t->data);
    for (node_t * sound = game->sounds->head; sound; sound = sound->next)
        destroy_sound(sound->data);
    for (node_t * music = game->musics->head; music; music = music->next)
        destroy_music(music->data);
    for (node_t * font = game->fonts->head; font; font = font->next)
        destroy_font(font->data);
    list_free(game->hover_buttons, false);
    list_free(game->textures, false);
    list_free(game->sounds, false);
    list_free(game->musics, false);
    list_free(game->fonts, false);
}

void destroy_game(graphic_t * game)
{
    destroy_lists(game);
    destroy_drawables(game);
    sfRenderWindow_destroy(game->window);
    sfClock_destroy(game->game_clock);
    sfView_destroy(game->view);
    for (int i = 0; i < game->nb_scenes; i++)
        free(game->layers_options[i]);
    free(game->layers_options);
    free(game->ids);
    free(game);
}
