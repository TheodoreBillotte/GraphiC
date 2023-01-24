/*
** EPITECH PROJECT, 2022
** musics
** File description:
** header file for musics functions
*/

#ifndef MUSICS
    #define MUSICS

    #include <SFML/Audio.h>
    #include "graphic.h"

music_t * build_music(graphic_t * graphic, char * path, float volume, int loop);
music_t * get_music(graphic_t * graphic, int music_id);
void play_music(graphic_t * graphic, int music_id);
void stop_music(graphic_t * graphic, int music_id);
void destroy_music(music_t * music);

#endif
