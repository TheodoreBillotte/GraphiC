/*
** EPITECH PROJECT, 2022
** events
** File description:
** header file for events functions
*/

#ifndef EVENTS
    #define EVENTS

    #include "graphic.h"

void play_events(graphic_t * graphic);
void play_button(graphic_t * graphic, sfMouseButtonEvent mouse);
void cond_click(graphic_t *graphic, sfMouseButtonEvent mouse,
                        button_t *button);
void check_hover(graphic_t * graphic);
void cond_hover(graphic_t *graphic, sfVector2i mouse_pos,
                    button_t *button);
void release_button(graphic_t *graphic, sfMouseButtonEvent button);
void check_release(graphic_t *p_graphic, sfMouseButtonEvent mouse,
                    button_t *p_button);
void check_enter(graphic_t *graphic, button_t *button);
void check_exit(graphic_t *graphic, sfVector2i mouse);

#endif
