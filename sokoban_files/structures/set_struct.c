/*
** EPITECH PROJECT, 2022
** set_struct.c
** File description:
** set_struct
*/

#include <stdlib.h>
#include "my_sokoban.h"
#include "my_macro.h"
#include "my_lib.h"

void get_info(sokoban_t *soko);
void get_targets(sokoban_t *soko);

static void set_struct_map(sokoban_t *soko)
{
    soko->map->nb_line = 0;
    soko->map->column_max = 0;
    soko->map->nb_boxes = 0;
    soko->map->nb_targets = 0;
    soko->map->map_array = my_str_to_word_array(soko->map->map, '\n');
    soko->map->map_init = my_str_to_word_array(soko->map->map, '\n');
}

static void set_struct_obstacles(sokoban_t *soko)
{
    soko->obstacles->boxes = UNEXIST;
    soko->obstacles->target = UNEXIST;
    soko->obstacles->next_move = NOT_DONE;
    soko->obstacles->box_on_target = NO;
    soko->obstacles->up_down = 0;
    soko->obstacles->left_right = 0;
}

static void set_struct_end_game(sokoban_t *soko)
{
    soko->end_g->boxes_on_targets = 0;
    soko->end_g->boxes_blocked = 0;
    soko->end_g->end_game = -42;
    return;
}

static void set_struct_player(sokoban_t *soko)
{
    soko->player->new_player_y = 0;
    soko->player->new_player_x = 0;
    soko->player->old_player_y = 0;
    soko->player->old_player_x = 0;
}

int set_struct(sokoban_t *soko)
{
    set_struct_end_game(soko);
    set_struct_obstacles(soko);
    set_struct_player(soko);
    set_struct_map(soko);
    get_targets(soko);
    get_info(soko);
    return (SUCCESS);
}