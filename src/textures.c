/*
** EPITECH PROJECT, 2023
** textures
** File description:
** file for textures functions
*/

#include <malloc.h>
#include "graphic.h"

texture_t * build_texture(graphic_t * graphic, char * path)
{
    texture_t * texture;
    sfTexture * image = sfTexture_createFromFile(path, NULL);

    if (image == NULL)
        return NULL;

    texture = malloc(sizeof(texture_t));

    texture->texture = image;
    texture->id = list_size(graphic->textures);
    list_append(graphic->textures, texture);

    return texture;
}

texture_t * get_texture(graphic_t * graphic, int id)
{
    return list_get(graphic->textures, id);
}

void destroy_texture(texture_t * texture)
{
    sfTexture_destroy(texture->texture);
    free(texture);
}
