/*
** EPITECH PROJECT, 2022
** display_map.c
** File description:
** display_map
*/

#include <ncurses.h>
#include <strings.h>
#include "my_sokoban.h"
#include "my_lib.h"

void get_info(sokoban_t *soko)
{
    int x_max = 0;

    for (int i = 0; soko->map->map_init[i] != NULL; ++i)
        ++soko->map->nb_line;
    for (int y = 0, x = 0; soko->map->map_init[y] != NULL; ++y, x = 0) {
        for (; soko->map->map_init[y][x] != '\0'; ++x);
        if (y == 0) {
            x_max = x;
            soko->map->column_max = x_max;
        }
        if (y != 0 && x > x_max) {
            x_max = x;
            soko->map->column_max = x_max;
        }
    }
    return;
}

void display_map(sokoban_t *soko)
{
    int y = 0;
    int x = 0;

    getmaxyx(stdscr, y, x);
    if (y < soko->map->nb_line || x < soko->map->column_max)
        mvprintw((y / 2), (x / 2) - my_strlen("Window Too Small\n"),
        "%s\n", "Window Too Small\n");
    else {
        for (int i = 0; soko->map->map_array[i] != NULL; ++i)
            mvprintw((LINES / 2 + i - soko->map->nb_line / 2),
            COLS / 2 - soko->map->column_max / 2,
            "%s\n", soko->map->map_array[i]);
    }
    return;
}

void reset_map(sokoban_t *soko, const int key)
{
    if (key == 32)
        soko->map->map_array = my_arraycpy(soko->map->map_init);
    return;
}
