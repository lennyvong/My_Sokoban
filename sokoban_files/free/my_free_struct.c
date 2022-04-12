/*
** EPITECH PROJECT, 2022
** my_free_struct.c
** File description:
** my_free_struct
*/

#include <stdlib.h>
#include "my_sokoban.h"
#include "my_free.h"

void my_free_struct(sokoban_t *soko)
{
    free(soko->map->map);
    my_free_array(soko->map->map_init);
    my_free_array(soko->map->map_array);
    return;
}
