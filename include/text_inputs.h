/*
** EPITECH PROJECT, 2023
** text_inputs
** File description:
** file for text inputs functions
*/

#ifndef TEXT_INPUTS_H
    #define TEXT_INPUTS_H

    #include "graphic.h"
    #include "drawables.h"
    #include "fonts.h"

text_input_t *build_text_input(graphic_t *graphic,
                            text_input_constructor_t constructor);
void destroy_text_input(text_input_t *text_input);
void destroy_text_input_list(list_t *list);
void draw_text_input(graphic_t *graphic, text_input_t *text_input);
void setup_text_input(graphic_t *graphic, text_input_t *text_input,
                        text_input_constructor_t constructor);
void text_input_click(graphic_t *graphic, text_input_t *text_input,
                        sfMouseButtonEvent button);
void text_input_key_pressed(graphic_t *graphic, text_input_t *text_input,
                            sfTextEvent event);
void text_input_release(graphic_t *graphic, text_input_t *text_input,
                        sfMouseButtonEvent button);

#endif
