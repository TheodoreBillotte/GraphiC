/*
** EPITECH PROJECT, 2022
** sounds
** File description:
** file for sounds functions
*/

#include <SFML/Audio.h>
#include <stdlib.h>

#include "sounds.h"
#include "graphic.h"

sound_t * build_sound(graphic_t * graphic, char * path)
{
    sfSound * sound = sfSound_create();
    sfSoundBuffer * buffer = sfSoundBuffer_createFromFile(path);
    sound_t * new_sound = malloc(sizeof(sound_t));

    sfSound_setBuffer(sound, buffer);
    new_sound->sound = sound;
    new_sound->buffer = buffer;
    list_append(graphic->sounds, new_sound);
    return new_sound;
}

sound_t * get_sound(graphic_t * graphic, int sound_id)
{
    node_t * sound = graphic->sounds->head;

    while (sound && ((sound_t *) sound->data)->id != sound_id)
        sound = sound->next;
    return (sound_t *) sound->data;
}

void play_sound(graphic_t * graphic, float volume, int sound_id)
{
    sound_t * sound = get_sound(graphic, sound_id);
    sfSound_setVolume(sound->sound, volume);
    sfSound_play(sound->sound);
}

void destroy_sound(sound_t * sound)
{
    sfSound_destroy(sound->sound);
    sfSoundBuffer_destroy(sound->buffer);
    free(sound);
}
