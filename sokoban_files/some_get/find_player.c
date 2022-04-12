/*
** EPITECH PROJECT, 2022
** get_player_pos.c
** File description:
** get_player_pos
*/

#include <stdlib.h>
#include "my_macro.h"
#include "my_sokoban.h"

static int is_x(sokoban_t *soko, int const y)
{
    for (int x = 0; soko->map->map_array[y][x] != '\0'; x++) {
        if (soko->map->map_array[y][x] == 'P') {
            soko->player->old_player_y = y;
            soko->player->old_player_x = x;
            return (SUCCESS);
        }
    }
    return (ERROR);
}

int find_player(sokoban_t *soko)
{
    for (int y = 0; soko->map->map_array[y] != NULL; y++) {
        if (is_x(soko, y) == SUCCESS)
            break;
    }
    return (SUCCESS);
}
