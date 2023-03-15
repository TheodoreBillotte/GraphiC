/*
** EPITECH PROJECT, 2023
** dropdown_utils
** File description:
** file for dropdown utils functions
*/

#include "dropdown.h"

void change_bg_pos(dropdown_t *dropdown)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(dropdown->sprite);
    sfVector2f bg = sfRectangleShape_getPosition(dropdown->bg);
    sfVector2f pos = sfSprite_getPosition(dropdown->sprite);

    bg.x = dropdown->extend_side == LEFT ? pos.x -
            sfRectangleShape_getSize(dropdown->bg).x :
            dropdown->extend_side == RIGHT ? pos.x + rect.width : pos.x;
    bg.y = dropdown->extend_side == BOTTOM ? pos.y + rect.height : pos.y;
    sfRectangleShape_setPosition(dropdown->bg, bg);
}
