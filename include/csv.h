/*
** EPITECH PROJECT, 2023
** csv
** File description:
** file for csv functions
*/

#ifndef CSV_H
    #define CSV_H

    #include <stddef.h>
    #include <malloc.h>
    #include <graphic.h>

typedef struct csv_s {
    int **csv;
    sfVector2i size;
} csv_t;

char **get_csv_line(char *line, int line_size);
csv_t *transform_csv(char ***csv, sfVector2i size);
void free_csv_buffer(char ***csv, sfVector2i size);
csv_t *get_csv(char *path);
void free_csv(csv_t *csv);

#endif
