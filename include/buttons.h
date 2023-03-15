/*
** EPITECH PROJECT, 2022
** buttons
** File description:
** header file for buttons functions
*/

#ifndef BUTTONS
    #define BUTTONS

    #include "graphic.h"

button_t * build_button(graphic_t * graphic, int texture_id,
                        int scene, int layer);
void draw_buttons(graphic_t * graphic);
void destroy_button(button_t * button);
void update_button(button_t * button);
button_t * get_button(graphic_t * graphic, int id);
void destroy_button_list(list_t * list);
void cond_click_button(graphic_t *graphic, sfMouseButtonEvent mouse,
                       button_t *button);

#endif
