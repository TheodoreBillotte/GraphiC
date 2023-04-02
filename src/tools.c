/*
** EPITECH PROJECT, 2023
** tools
** File description:
** file for tools functions
*/

#include "tools.h"

int count_chars_delim(const char *line, char c, char delim)
{
    int count = 0;

    for (int i = 0; line[i] != '\0' && line[i] != delim; i++) {
        if (line[i] == c)
            count++;
    }
    return count;
}

int strlen_delim(const char *line, char delim)
{
    int i = 0;

    for (; line[i] != '\0' && line[i] != delim; i++);
    return i;
}

int my_strnbr(const char *str)
{
    int nbr = 0;
    int neg = 1;

    if (str[0] == '-') {
        neg = -1;
        str++;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        nbr *= 10;
        nbr += str[i] - '0';
    }
    return nbr * neg;
}
