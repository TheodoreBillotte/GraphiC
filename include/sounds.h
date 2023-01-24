/*
** EPITECH PROJECT, 2022
** sounds
** File description:
** heder file for sounds functions and structure
*/

#ifndef SOUNDS
    #define SOUNDS

    #include <SFML/Audio.h>
    #include "graphic.h"

sound_t * build_sound(graphic_t * graphic, char * path);
sound_t * get_sound(graphic_t * graphic, int sound_id);
void play_sound(graphic_t * graphic, float volume, int sound_id);
void destroy_sound(sound_t * sound);

#endif
