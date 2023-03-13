/*
** EPITECH PROJECT, 2023
** sliders
** File description:
** file for sliders functions
*/

#ifndef SLIDERS_H
    #define SLIDERS_H

    #include "graphic.h"

slider_t *build_slider(graphic_t *graphic, slider_constructor_t constructor);
void update_slider(graphic_t *graphic, slider_t *slider);
void update_sliders(graphic_t *graphic);
void slider_bar_click(graphic_t *graphic, slider_t *slider,
                    sfMouseButtonEvent mouse);
void slider_bar_release(graphic_t *graphic, slider_t *slider,
                    sfMouseButtonEvent mouse);
void destroy_slider_list(list_t *list);
void destroy_slider(slider_t *slider);
void slider_set_values(graphic_t *graphic, slider_t *slider,
                        slider_constructor_t constructor);

#endif
