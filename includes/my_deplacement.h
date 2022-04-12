/*
** EPITECH PROJECT, 2022
** my_deplacement.h
** File description:
** my_deplacement
*/

#ifndef MY_DEPLACEMENT_H_
    #define MY_DEPLACEMENT_H_

typedef struct sokoban_s sokoban_t;

/*  PLAYER */
void which_move(sokoban_t *soko, int key);
void player_move(sokoban_t *soko);
int check_wall_player(sokoban_t *soko, int key);
/* BOXES */
int check_boxes(sokoban_t *soko, int key);
int check_wall_boxes(sokoban_t *soko, int const key);
/* TARGETS */
#endif /* !MY_DEPLACEMENT_H_ */
