/*
** EPITECH PROJECT, 2023
** mouse_management
** File description:
** file for mouse management functions
*/

#include "graphic.h"

sfVector2f get_mouse_pos(sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    return sfRenderWindow_mapPixelToCoords(window, mouse_pos,
                        sfRenderWindow_getView(window));
}
