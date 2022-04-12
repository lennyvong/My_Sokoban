/*
** EPITECH PROJECT, 2022
** my_main.h
** File description:
** my_main
*/

#ifndef MY_MAIN_H_
    #define MY_MAIN_H_

typedef struct sokoban_s sokoban_t;

int my_sokoban(sokoban_t *soko);
int get_map(char **av, sokoban_t *soko);
void my_free_struct(sokoban_t *soko);
#endif /* !MY_MAIN_H_ */
