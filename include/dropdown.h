/*
** EPITECH PROJECT, 2023
** dropdown
** File description:
** file for dropdown functions
*/

#ifndef DROPDOWN_H
    #define DROPDOWN_H

    #include "graphic.h"
    #include "textures.h"
    #include "graphic.h"

dropdown_t *build_dropdown(graphic_t * graphic,
                            dropdown_constructor_t constructor);
button_t *dropdown_add_button(graphic_t *graphic, dropdown_t *dropdown,
                            int texture_id);
void destroy_dropdown(dropdown_t *dropdown);
void destroy_dropdown_list(list_t *dropdowns);
void cond_click_dropdown(graphic_t *graphic, dropdown_t *dropdown,
                            sfMouseButtonEvent mouse);
void cond_dropdown_release(graphic_t *graphic, dropdown_t *dropdown,
                            sfMouseButtonEvent button);
void draw_dropdown(graphic_t *graphic, dropdown_t *dropdown);
void draw_dropdown_button(graphic_t *graphic, button_t *button);
void cond_dropdown_hover(graphic_t *graphic, sfVector2i mouse,
                            dropdown_t *dropdown);
void setup_new_button(dropdown_t *dropdown, button_t *button);
void change_bg_pos(dropdown_t *dropdown);

#endif
