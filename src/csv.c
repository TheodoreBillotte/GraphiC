/*
** EPITECH PROJECT, 2023
** csv
** File description:
** file for csv functions
*/

#include <sys/stat.h>
#include <SFML/System/Vector2.h>
#include "csv.h"
#include "tools.h"

char **get_csv_line(char *line, int line_size, char delim)
{
    char **csv_line = malloc(sizeof(char *) * (line_size + 2));
    int j = 0;
    int k = 0;

    csv_line[j] = malloc(strlen_delim(line, delim) + 1);
    for (int i = 0; line[i] != '\0' && line[i] != '\n'; i++) {
        if (line[i] == delim) {
            csv_line[j++][k] = '\0';
            csv_line[j] = malloc(strlen_delim(line + i + 1, delim) + 2);
            k = 0;
        } else
            csv_line[j][k++] = line[i];
    }
    csv_line[j][k] = '\0';
    csv_line[j + 1] = NULL;
    return csv_line;
}

char ***get_csv(char *path, char delim)
{
    FILE *file = fopen(path, "r");
    struct stat st;char ***buffer;
    sfVector2i size;char **line;
    char *file_buffer;
    stat(path, &st);
    char *file_reader = malloc(sizeof(char) * st.st_size + 1);
    file_buffer = file_reader;
    fread(file_buffer, st.st_size, 1, file);
    file_buffer[st.st_size] = '\0';
    size = (sfVector2i) {count_chars_delim(file_buffer, '\n', '\0'),
                        count_chars_delim(file_buffer, delim, '\n') + 1};
    buffer = malloc(sizeof(char **) * (size.x + 1));
    for (int i = 0; i < size.x; i++) {
        line = get_csv_line(file_buffer, size.y, delim);
        buffer[i] = line;
        file_buffer += strlen_delim(file_buffer, '\n') + 1;
    }
    buffer[size.x] = NULL;
    free(file_reader);
    return buffer;
}

int **transform_csv(char ***csv)
{
    sfVector2i size = (sfVector2i) {0, 0};
    int **buffer;

    for (; csv[size.x]; size.x++);
    for (; csv[0][size.y]; size.y++);
    buffer = malloc(sizeof(int *) * (size.x + 1));
    for (int i = 0; i < size.x; i++) {
        buffer[i] = malloc(sizeof(int) * (size.y + 1));
        for (int j = 0; j < size.y; j++)
            buffer[i][j] = my_strnbr(csv[i][j]);
        buffer[i][size.y] = -2;
    }
    buffer[size.x] = NULL;
    free_csv(csv);
    return buffer;
}

void free_csv(char ***csv)
{
    for (int i = 0; csv[i]; i++) {
        for (int j = 0; csv[i][j]; j++)
            free(csv[i][j]);
        free(csv[i]);
    }
    free(csv);
}

void free_csv_int(int **csv)
{
    for (int i = 0; csv[i]; i++)
        free(csv[i]);
    free(csv);
}
