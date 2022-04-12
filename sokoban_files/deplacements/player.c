/*
** EPITECH PROJECT, 2022
** players.c
** File description:
** players
*/

#include <ncurses.h>
#include "my_macro.h"
#include "my_sokoban.h"
#include "my_lib.h"

void is_player_on_target(sokoban_t *soko);

void which_move(sokoban_t *soko, int const key)
{

    if (key == 67) {
        soko->player->new_player_y = soko->player->old_player_y;
        soko->player->new_player_x = soko->player->old_player_x + 1;
    }
    if (key == 68) {
        soko->player->new_player_y = soko->player->old_player_y;
        soko->player->new_player_x = soko->player->old_player_x - 1;
    }
    if (key == 66) {
        soko->player->new_player_y = soko->player->old_player_y + 1;
        soko->player->new_player_x = soko->player->old_player_x;
    }
    if (key == 65) {
        soko->player->new_player_y = soko->player->old_player_y - 1;
        soko->player->new_player_x = soko->player->old_player_x;
    }
    return;
}

void player_move(sokoban_t *soko)
{
    int y = soko->player->new_player_y;
    int x = soko->player->new_player_x;

    is_player_on_target(soko);
    soko->map->map_array[y][x] = 'P';
    if (soko->obstacles->boxes == EXIST) {
        soko->map->map_array[y + soko->obstacles->up_down]
        [x + soko->obstacles->left_right] = 'X';
    }
    return;
}

int check_wall_player(sokoban_t *soko, int const key)
{
    int y = soko->player->old_player_y;
    int x = soko->player->old_player_x;

    if (key == 67)
        if (soko->map->map_array[y][x + 1] == '#')
            return (ERROR);
    if (key == 68)
        if (soko->map->map_array[y][x - 1] == '#')
            return (ERROR);
    if (key == 66)
        if (soko->map->map_array[y + 1][x] == '#')
            return (ERROR);
    if (key == 65)
        if (soko->map->map_array[y - 1][x] == '#')
            return (ERROR);
    return (SUCCESS);
}
