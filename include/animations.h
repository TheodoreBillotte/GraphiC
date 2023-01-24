/*
** EPITECH PROJECT, 2022
** animations
** File description:
** header file for animations functions and structure
*/

#ifndef ANIMATIONS
    #define ANIMATIONS

    #include <SFML/Graphics.h>
    #include "actors.h"
    #include "graphic.h"

animation_t * build_animation(sfIntRect rect, sfVector2i size,
                                sfVector2i offset, int speed);
void destroy_animation(animation_t * animation);
void play_animation(actor_t * actor);

#endif
