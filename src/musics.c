/*
** EPITECH PROJECT, 2022
** musics
** File description:
** file for musics functions
*/

#include <SFML/Audio.h>
#include <stdlib.h>

#include "musics.h"
#include "graphic.h"

music_t * build_music(graphic_t * graphic, char * path, float volume, int loop)
{
    sfMusic * music = sfMusic_createFromFile(path);
    music_t * new_music = malloc(sizeof(music_t));

    sfMusic_setVolume(music, volume);
    sfMusic_setLoop(music, loop);

    new_music->music = music;
    new_music->id = list_size(graphic->musics);

    list_append(graphic->musics, new_music);
    return new_music;
}

music_t * get_music(graphic_t * graphic, int music_id)
{
    node_t * music = graphic->musics->head;

    while (music && ((music_t *) music->data)->id != music_id)
        music = music->next;
    return (music_t *) music->data;
}

void play_music(graphic_t * graphic, int music_id)
{
    music_t * music = get_music(graphic, music_id);
    sfMusic_play(music->music);
}

void stop_music(graphic_t * graphic, int music_id)
{
    music_t * music = get_music(graphic, music_id);
    sfMusic_stop(music->music);
}

void destroy_music(music_t * music)
{
    sfMusic_destroy(music->music);
    free(music);
}
