/*
** EPITECH PROJECT, 2022
** end_game.c
** File description:
** end_game
*/

#include <stdio.h>
#include "my_macro.h"
#include "my_sokoban.h"

static int is_boxes_blocked(sokoban_t *soko, const int y, const int x)
{
    if (soko->map->map_array[y][x] == 'X'
    && soko->map->map_array[y + 1][x] == '#'
    && (soko->map->map_array[y][x + 1] == '#'
    || soko->map->map_array[y][x - 1] == '#'))
        return (YES);
    if (soko->map->map_array[y][x] == 'X'
    && soko->map->map_array[y - 1][x] == '#'
    && (soko->map->map_array[y][x + 1] == '#'
    || soko->map->map_array[y][x - 1] == '#'))
        return (YES);
    return (NO);
}

static void is_boxes_placed(sokoban_t *soko, const int y)
{
    for (int x = 0; soko->map->map_array[y][x] != '\0'; ++x) {
        if (is_boxes_blocked(soko, y, x) == YES)
            ++soko->end_g->boxes_blocked;
        if (soko->map->map_array[y][x] == 'X'
        && soko->map->map_init[y][x] == 'O')
            ++soko->end_g->boxes_on_targets;
    }
    return;
}

void check_endgame(sokoban_t *soko)
{
    soko->end_g->boxes_on_targets = 0;
    soko->end_g->boxes_blocked = 0;
    for (int y = 0; soko->map->map_array[y] != NULL; ++y)
        is_boxes_placed(soko, y);
    if (soko->end_g->boxes_on_targets == soko->map->nb_targets)
        soko->end_g->end_game = WIN;
    if (soko->end_g->boxes_blocked == soko->map->nb_boxes)
        soko->end_g->end_game = LOOSE;
    return;
}
