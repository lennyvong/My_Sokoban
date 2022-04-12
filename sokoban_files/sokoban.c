/*
** EPITECH PROJECT, 2022
** bc
** File description:
** bs
*/

#include <ncurses.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_deplacement.h"
#include "my_sokoban.h"
#include "my_lib.h"
#include "my_macro.h"

void reset_boxes_positions(sokoban_t *soko);

void map_modification(sokoban_t *soko, int const key)
{
    if (key >= 65 && key <= 68) {
        find_player(soko);
        which_move(soko, key);
        soko->obstacles->boxes = check_boxes(soko, key);
        if (check_wall_player(soko, key) == SUCCESS
        && check_wall_boxes(soko, key) == SUCCESS)
            player_move(soko);
        reset_boxes_positions(soko);
    }
    check_endgame(soko);
    reset_map(soko, key);
    return;
}

int in_game(sokoban_t *soko)
{
    int key = -1;

    initscr();
    curs_set(0);
    while (1) {
        map_modification(soko, key);
        display_map(soko);
        if (soko->end_g->end_game == LOOSE || soko->end_g->end_game == WIN) {
            break;
        }
        key = getch();
        clear();
    }
    refresh();
    endwin();
    return (soko->end_g->end_game);
}

int my_sokoban(sokoban_t *soko)
{
    if (set_struct(soko) == ERROR)
        return (ERROR);
    return (in_game(soko));
}
