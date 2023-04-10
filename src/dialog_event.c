/*
** EPITECH PROJECT, 2023
** dialog_event
** File description:
** file for dialog event functions
*/

#include "graphic.h"
#include "dialog.h"
#include "tools.h"

void update_dialog(graphic_t *graphic, dialog_t *dialog)
{
    if (dialog->dialog && sfClock_getElapsedTime(dialog->clock).microseconds
                        / 1000 >= dialog->delay) {
        sfClock_restart(dialog->clock);
        if (dialog->on_update)
            dialog->on_update(graphic, dialog);
        if (dialog->dialog[dialog->dialog_index] &&
            dialog->dialog[dialog->dialog_index][dialog->text_index] != '\0') {
            dialog->display[dialog->text_index] =
                dialog->dialog[dialog->dialog_index][dialog->text_index];
            dialog->display[++dialog->text_index] = '\0';
        }
    }
}

void dialog_check_click(graphic_t *graphic, dialog_t *dialog,
                        sfMouseButtonEvent event)
{
    sfFloatRect bound = sfRectangleShape_getGlobalBounds(dialog->bg);

    if (!sfFloatRect_contains(&bound, event.x, event.y))
        return;
    if (dialog->on_click)
        dialog->on_click(graphic, dialog, event);
    skip_dialog(graphic, dialog);
}

void skip_dialog(graphic_t *graphic, dialog_t *dialog)
{
    if (!dialog->dialog)
        return;
    if (dialog->dialog[dialog->dialog_index] &&
        dialog->dialog[dialog->dialog_index][dialog->text_index] != '\0') {
        dialog->text_index =
                strlen_delim(dialog->dialog[dialog->dialog_index], '\0');
        for (int i = 0; i < dialog->text_index; i++)
            dialog->display[i] = dialog->dialog[dialog->dialog_index][i];
        dialog->display[dialog->text_index] = '\0';
    } else {
        dialog->dialog_index = dialog->dialog[dialog->dialog_index + 1] ==
                NULL ? 0 : dialog->dialog_index + 1;
        dialog->text_index = 0;
        dialog->display[0] = '\0';
        if (dialog->dialog_index == 0 && dialog->on_finish)
            dialog->on_finish(graphic, dialog);
    }
}
