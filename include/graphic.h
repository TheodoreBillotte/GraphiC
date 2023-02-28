/*
** EPITECH PROJECT, 2022
** graphic
** File description:
** header file for GraphiC library
*/

#ifndef GRAPHIC
    #define GRAPHIC

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include "list.h"

typedef struct drawables_s {
    list_t *actors;
    list_t *buttons;
    list_t *texts;
} drawables_t;

typedef struct ids_s {
    int button_id;
    int actor_id;
    int text_id;
} ids_t;

typedef struct graphic {
    sfRenderWindow *window;
    sfClock *game_clock;
    sfView *view;

    void *game_data;
    int nb_scenes;
    int nb_layers;
    int scene;

    list_t *textures;
    list_t *sounds;
    list_t *musics;
    list_t *fonts;
    list_t *hover_buttons;
    drawables_t **drawables;
    ids_t *ids;

    void (*init)(struct graphic *);
    void (*update)(struct graphic *);
    void (*close)(struct graphic *);
    void (*draw)(struct graphic *);
    void (*event)(struct graphic *, sfEvent *);
} graphic_t;

typedef struct {
    sfClock *clock;
    int height;
    int width;
    int speed;

    int x_offset;
    int y_offset;

    sfIntRect rect;
} animation_t;

typedef struct actor_s {
    animation_t *animation;
    sfSprite *sprite;
    sfFloatRect rect;

    int layer;
    int scene;
    int id;

    void (*update)(graphic_t *, struct actor_s *);
} actor_t;

typedef struct {
    sfText *text;

    int scene;
    int layer;
    int id;
} text_t;

typedef struct button button_t;
struct button {
    sfSprite *sprite;
    sfFloatRect rect;
    text_t *text;

    int scene;
    int id;

    void (*on_hover)(graphic_t *, button_t *);
    void (*on_enter)(graphic_t *, button_t *);
    void (*on_leave)(graphic_t *, button_t *);
    void (*on_release)(graphic_t *, button_t *, sfMouseButton);
    void (*on_click)(graphic_t *, button_t *, sfMouseButton);
};

typedef struct {
    sfSoundBuffer *buffer;
    sfSound *sound;
    int id;
} sound_t;

typedef struct {
    sfMusic *music;
    int id;
} music_t;

typedef struct {
    sfFont *font;
    int id;
} font_t;

typedef struct {
    sfTexture *texture;
    int id;
} texture_t;

graphic_t *build_game(sfRenderWindow *window, int nb_scenes, int nb_layers);
void init_game(graphic_t *game);
void game_update(graphic_t *graphic);
void destroy_game(graphic_t *game);
void dame_draw(graphic_t *graphic);

#endif
