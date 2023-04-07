/*
** EPITECH PROJECT, 2023
** dialog
** File description:
** file for dialog functions
*/

#ifndef DIALOG_H
    #define DIALOG_H

    #include <malloc.h>
    #include "graphic.h"
    #include "drawables.h"

dialog_t *build_dialog(graphic_t *graphic, dialog_constructor_t constructor);
void update_dialog(graphic_t *graphic, dialog_t *dialog);
void draw_dialog(graphic_t *graphic, dialog_t *dialog);
void skip_dialog(graphic_t *graphic, dialog_t *dialog);
void destroy_dialog(dialog_t *dialog);
void destroy_dialog_list(list_t *list);
void dialog_check_click(graphic_t *graphic, dialog_t *dialog,
                        sfMouseButtonEvent event);
void dialog_setup(graphic_t *graphic, dialog_t *dialog,
                dialog_constructor_t constructor);

#endif
