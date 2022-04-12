/*
** EPITECH PROJECT, 2022
** targets.c
** File description:
** targets
*/

#include "my_sokoban.h"
#include "my_macro.h"

void is_player_on_target(sokoban_t *soko)
{
    int y = soko->player->old_player_y;
    int x = soko->player->old_player_x;

    if (soko->map->map_init[y][x] == 'O')
        soko->map->map_array[y][x] = 'O';
    else
        soko->map->map_array[y][x] = ' ';
    return;
}
