/*
** EPITECH PROJECT, 2022
** animations
** File description:
** file for animations functions
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "actors.h"
#include "animations.h"

animation_t * build_animation(sfIntRect rect, sfVector2i size,
                                sfVector2i offset, int speed)
{
    animation_t * animation = malloc(sizeof(animation_t));
    animation->clock = sfClock_create();
    animation->height = size.y;
    animation->width = size.x;
    animation->speed = speed;
    animation->x_offset = offset.x;
    animation->y_offset = offset.y;
    animation->rect = rect;
    return animation;
}

void play_animation(actor_t * actor)
{
    if (!(actor->animation))
        return;
    if (sfClock_getElapsedTime(actor->animation->clock).microseconds >=
                                    1000000 / actor->animation->speed) {
        if (actor->animation->width > actor->animation->rect.left +
            actor->animation->rect.width) {
            actor->animation->rect.left += actor->animation->rect.width +
                actor->animation->x_offset;
        } else {
            actor->animation->rect.left = 0;
            actor->animation->rect.top = actor->animation->rect.top +
                actor->animation->rect.height >= actor->animation->height ? 0 :
                actor->animation->rect.top + actor->animation->rect.height +
                actor->animation->y_offset;
        }
        sfSprite_setTextureRect(actor->sprite, actor->animation->rect);
        sfClock_restart(actor->animation->clock);
    }
}

void destroy_animation(animation_t * animation)
{
    sfClock_destroy(animation->clock);
    free(animation);
}
