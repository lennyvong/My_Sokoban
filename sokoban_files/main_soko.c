/*
** EPITECH PROJECT, 2022
** main_soko.c
** File description:
** main_soko
*/

#include <stdlib.h>
#include "my_error.h"
#include "my_macro.h"
#include "my_lib.h"
#include "my_free.h"
#include "my_sokoban.h"
#include "my_main.h"

static int malloc_struct(sokoban_t *soko)
{
    soko->obstacles = malloc(sizeof(*soko->obstacles));
    if (soko->obstacles == NULL)
        return (ERROR);
    soko->map = malloc(sizeof(*soko->map));
    if (soko->map == NULL)
        return (ERROR);
    soko->player = malloc(sizeof(*soko->player));
    if (soko->player == NULL)
        return (ERROR);
    soko->end_g = malloc(sizeof(*soko->end_g));
    if (soko->end_g == NULL)
        return (ERROR);
    return (SUCCESS);
}

int main(int ac, char **av)
{
    char *map = NULL;
    sokoban_t soko;
    int ret = 0;

    ret = error_handling(ac, av, map);
    if (ret == SUCCESS) {
        if (malloc_struct(&soko) == ERROR)
            return (ERROR);
        if (get_map(av, &soko) == SUCCESS) {
            ret = my_sokoban(&soko);
            free(map);
            my_free_struct(&soko);
            return (ret);
        }
    }
    if (ret == -42)
        return (0);
    return (ERROR);
}
