/*
** EPITECH PROJECT, 2022
** get_targets.c
** File description:
** get_targets
*/

#include "my_sokoban.h"

void get_targets(sokoban_t *soko)
{
    for (int i = 0; soko->map->map[i] != '\0'; ++i) {
        if (soko->map->map[i] == 'O')
            ++soko->map->nb_targets;
        if (soko->map->map[i] == 'X')
            ++soko->map->nb_boxes;
    }
    return;
}
