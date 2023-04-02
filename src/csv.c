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

char **get_csv_line(char *line, int line_size)
{
    char **csv_line = malloc(sizeof(char *) * (line_size + 2));
    int j = 0;
    int k = 0;

    csv_line[j] = malloc(strlen_delim(line, ',') + 1);
    for (int i = 0; line[i] != '\0' && line[i] != '\n'; i++) {
        if (line[i] == ',') {
            csv_line[j++][k] = '\0';
            csv_line[j] = malloc(strlen_delim(line + i + 1, ',') + 2);
            k = 0;
        } else
            csv_line[j][k++] = line[i];
    }
    csv_line[j][k] = '\0';
    csv_line[j + 1] = NULL;
    return csv_line;
}

csv_t *get_csv(char *path)
{
    FILE *file = fopen(path, "r");
    struct stat st;
    char ***buffer;
    sfVector2i size;
    char **line;
    char *file_buffer;

    stat(path, &st);
    file_buffer = malloc(sizeof(char) * st.st_size + 1);
    fread(file_buffer, st.st_size, 1, file);
    file_buffer[st.st_size] = '\0';
    size = (sfVector2i) {count_chars_delim(file_buffer, '\n', '\0'),
                        count_chars_delim(file_buffer, ',', '\n') + 1};
    buffer = malloc(sizeof(char **) * size.x + 1);
    for (int i = 0; i < size.x; i++) {
        line = get_csv_line(file_buffer, size.y);
        buffer[i] = line;
        file_buffer += strlen_delim(file_buffer, '\n') + 1;
    }
    return transform_csv(buffer, size);
}

csv_t *transform_csv(char ***csv, sfVector2i size)
{
    int **buffer = malloc(sizeof(int *) * (size.x + 1));
    csv_t *csv_buffer = malloc(sizeof(csv_t));

    for (int i = 0; i < size.x; i++) {
        buffer[i] = malloc(sizeof(int) * (size.y + 1));
        for (int j = 0; j < size.y; j++)
            buffer[i][j] = my_strnbr(csv[i][j]);
        buffer[i][size.y] = -1;
    }
    buffer[size.x] = NULL;
    free_csv_buffer(csv, size);
    csv_buffer->csv = buffer;
    csv_buffer->size = size;
    return csv_buffer;
}

void free_csv_buffer(char ***csv, sfVector2i size)
{
    for (int i = 0; i < size.x; i++) {
        for (int j = 0; j < size.y; j++)
            free(csv[i][j]);
        free(csv[i]);
    }
    free(csv);
}
