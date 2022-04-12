/*
** EPITECH PROJECT, 2022
** boxes.c
** File description:
** boxes
*/

#include "my_sokoban.h"
#include "my_macro.h"

void reset_boxes_positions(sokoban_t *soko)
{
    soko->obstacles->left_right = 0;
    soko->obstacles->up_down = 0;
    return;
}

int check_wall_boxes(sokoban_t *soko, int const key)
{
    int y = soko->player->old_player_y;
    int x = soko->player->old_player_x;

    if (soko->obstacles->boxes == EXIST && key == 67)
        if (soko->map->map_array[y][x + 2] == '#'
        || soko->map->map_array[y][x + 2] == 'X')
            return (ERROR);
    if (soko->obstacles->boxes == EXIST && key == 68)
        if (soko->map->map_array[y][x - 2] == '#'
        || soko->map->map_array[y][x - 2] == 'X')
            return (ERROR);
    if (soko->obstacles->boxes == EXIST && key == 66)
        if (soko->map->map_array[y + 2][x] == '#'
        || soko->map->map_array[y + 2][x] == 'X')
            return (ERROR);
    if (soko->obstacles->boxes == EXIST && key == 65)
        if (soko->map->map_array[y - 2][x] == '#'
        || soko->map->map_array[y - 2][x] == '#')
            return (ERROR);
    return (SUCCESS);
}

int check_boxes(sokoban_t *soko, int const key)
{
    int y = soko->player->old_player_y;
    int x = soko->player->old_player_x;

    if (key == 67 && soko->map->map_array[y][x + 1] == 'X') {
        soko->obstacles->left_right = 1;
        return (EXIST);
    }
    if (key == 68 && soko->map->map_array[y][x - 1] == 'X') {
        soko->obstacles->left_right = -1;
        return (EXIST);
    }
    if (key == 66 && soko->map->map_array[y + 1][x] == 'X') {
        soko->obstacles->up_down = 1;
        return (EXIST);
    }
    if (key == 65 && soko->map->map_array[y - 1][x] == 'X') {
        soko->obstacles->up_down = -1;
        return (EXIST);
    }
    return (UNEXIST);
}
