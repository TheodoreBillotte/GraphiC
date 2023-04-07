/*
** EPITECH PROJECT, 2023
** dialog
** File description:
** file for dialog functions
*/

#include "dialog.h"
#include "fonts.h"

dialog_t *build_dialog(graphic_t *graphic, dialog_constructor_t constructor)
{
    dialog_t *dialog = malloc(sizeof(dialog_t));
    *dialog = (dialog_t) {0};
    dialog->scene = constructor.scene;
    dialog->layer = constructor.layer;
    dialog->clock = sfClock_create();
    dialog->delay = constructor.delay;
    dialog->id = graphic->ids->dialog_id++;
    dialog->display = malloc(sizeof(char) * (constructor.max_char + 1));
    dialog_setup(graphic, dialog, constructor);
    if (dialog->scene == -1)
        list_append(graphic->ui_layers[dialog->layer].dialogs, dialog);
    else
        list_append(get_scene_drawable(graphic, dialog->scene, dialog->layer)
                    .dialogs, dialog);
    return dialog;
}

void dialog_setup(graphic_t *graphic, dialog_t *dialog,
                dialog_constructor_t constructor)
{
    dialog->bg = sfRectangleShape_create();
    sfRectangleShape_setSize(dialog->bg, constructor.bg_size);
    sfRectangleShape_setFillColor(dialog->bg, constructor.bg_color);
    sfRectangleShape_setPosition(dialog->bg, constructor.bg_pos);
    dialog->text = sfText_create();
    sfText_setFont(dialog->text, get_font(graphic, constructor.font)->font);
    sfText_setCharacterSize(dialog->text, constructor.char_size);
    sfText_setColor(dialog->text, constructor.text_color);
    sfText_setPosition(dialog->text, constructor.text_pos);
}

void draw_dialog(graphic_t *graphic, dialog_t *dialog)
{
    sfRenderWindow_drawRectangleShape(graphic->window, dialog->bg, NULL);
    sfText_setString(dialog->text, dialog->display);
    sfRenderWindow_drawText(graphic->window, dialog->text, NULL);
}

void destroy_dialog(dialog_t *dialog)
{
    sfRectangleShape_destroy(dialog->bg);
    sfClock_destroy(dialog->clock);
    sfText_destroy(dialog->text);
    free(dialog->display);
    free(dialog);
}

void destroy_dialog_list(list_t *list)
{
    node_t *node = list->head;

    for (; node; node = node->next)
        destroy_dialog(node->data);
    list_free(list, false);
}
