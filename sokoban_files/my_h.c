/*
** EPITECH PROJECT, 2022
** my_h.c
** File description:
** my_h
*/

#include <unistd.h>

void my_h(void)
{
    write(1, "USAGE\n\t./my_sokoban map\n", 24);
    write(1, "DESCRIPTION\n\tmap file representing the warehouse map,", 53);
    write(1, " containing '#' for walls,\n\t\t'P' for the player,", 48);
    write(1, " 'X' for boxes and 'O' for storages locations.\n", 47);
    return;
}