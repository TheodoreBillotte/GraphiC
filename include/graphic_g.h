/*
** EPITECH PROJECT, 2022
** graphic_g
** File description:
** global header for GraphiC library
*/

#ifndef GRAPHIC_G
    #define GRAPHIC_G

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
    void (*on_release)(graphic_t *, button_t *);
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

graphic_t * build_game(sfRenderWindow * window);
void init_game(graphic_t * game);
void game_update(graphic_t * graphic);
void destroy_game(graphic_t * game);
void dame_draw(graphic_t *p_graphic);

actor_t * build_actor(graphic_t * graphic, char * image, sfVector2f position,
                        int menu);
void update_actor(actor_t * actor);
void destroy_actor(actor_t * actor);
void remove_actor(graphic_t * graphic, int id);
void draw_actors(graphic_t * graphic);
actor_t * get_actor(graphic_t * graphic, int id);

animation_t * build_animation(sfIntRect rect, sfVector2i size,
                                sfVector2i offset, int speed);
void destroy_animation(animation_t * animation);
void play_animation(actor_t * actor);

button_t * build_button(graphic_t * graphic, char * path,
                        sfVector2f position, int scene);
void draw_buttons(graphic_t * graphic);
void destroy_button(button_t * button);
void setup_button(button_t * button);
void update_button(button_t * button);
button_t * get_button(graphic_t * graphic, int id);

int sort_by_layer_actor_cmp(actor_t * a, actor_t * b);
int sort_by_layer_button_cmp(button_t * a, button_t * b);

void play_events(graphic_t * graphic);
void play_button(graphic_t * graphic, sfMouseButtonEvent mouse);
void check_hover(graphic_t * graphic);

font_t * build_font(graphic_t *graphic, char * path);
font_t * get_font(graphic_t * graphic, int id);
void destroy_font(font_t * font);

music_t * build_music(graphic_t * graphic, char * path, float volume, int loop);
music_t * get_music(graphic_t * graphic, int music_id);
void play_music(graphic_t * graphic, int music_id);
void stop_music(graphic_t * graphic, int music_id);
void destroy_music(music_t * music);

sound_t * build_sound(graphic_t * graphic, char * path);
sound_t * get_sound(graphic_t * graphic, int sound_id);
void play_sound(graphic_t * graphic, float volume, int sound_id);
void destroy_sound(sound_t * sound);

sfText * build_text(graphic_t * graphic, char * string, int font_id, int size);
void draw_text(graphic_t * graphic, sfText *text, sfVector2f position);
void destroy_text(sfText * text);

#endif
