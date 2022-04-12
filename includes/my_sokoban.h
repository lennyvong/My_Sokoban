/*
** EPITECH PROJECT, 2022
** my_sokoban.h
** File description:
** my_sokoban
*/

#ifndef MY_SOKOBAN_H_
    #define MY_SOKOBAN_H_

typedef struct obstables_s {
    int boxes;
    int target;
    int box_on_target;
    int next_move;
    int up_down;
    int left_right;
} obstables_t;

typedef struct player_s {
    int old_player_x;
    int old_player_y;
    int new_player_x;
    int new_player_y;
} player_t;

typedef struct maps_s {
    char *map;
    char **map_init;
    char **map_array;
    int nb_line;
    int column_max;
    int nb_boxes;
    int nb_targets;
} maps_t;

typedef struct end_game_s {
    int boxes_on_targets;
    int boxes_blocked;
    int end_game;
} end_game_t;

typedef struct sokoban_s {
    obstables_t *obstacles;
    player_t *player;
    maps_t *map;
    end_game_t *end_g;
} sokoban_t;

/* MAPS */
void display_map(sokoban_t *soko);
void reset_map(sokoban_t *soko, const int key);
/*  SOME GET */
int find_player(sokoban_t *soko);
/* END_GAME */
void check_endgame(sokoban_t *soko);
/* OTHERS */
int set_struct(sokoban_t *soko);
#endif /* !MY_SOKOBAN_H_ */
