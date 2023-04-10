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

char **get_csv_line(char *line, int line_size, char delim);
int **transform_csv(char ***csv);
void free_csv(char ***csv);
char ***get_csv(char *path, char delim);
void free_csv_int(int **csv);

#endif
