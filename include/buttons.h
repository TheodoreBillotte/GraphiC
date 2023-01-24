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
                        sfVector2f position, int scene);
void draw_buttons(graphic_t * graphic);
void destroy_button(button_t * button);
void update_button(button_t * button);
button_t * get_button(graphic_t * graphic, int id);

#endif
