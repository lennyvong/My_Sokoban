/*
** EPITECH PROJECT, 2022
** error.c
** File description:
** error
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_free.h"
#include "my_macro.h"
#include "my_lib.h"

char **my_str_to_word_array(char *str, char p_break);
void my_h(void);

static int check_element(char elem)
{
    if (elem != '#' && elem != ' ' && elem != '\n' && elem != 'X'
    && elem != 'O' && elem != 'P')
        return (ERROR);
    return (SUCCESS);
}

static int checking_map(char *map)
{
    char **map2D = my_str_to_word_array(map, '\n');

    for (int y = 1; map2D[y] != NULL; y++)
        for (int x = 0; map2D[y][x] != '\0'; x++)
            if (check_element(map2D[y][x]) == ERROR) {
                my_free_array(map2D);
                return (ERROR);
            }
    my_free_array(map2D);
    return (SUCCESS);
}

static int get_map(char **av, char *map)
{
    struct stat bytes;
    int fd = 0;
    int ret = 0;

    stat(av[1], &bytes);
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return (ERROR);
    map = malloc(sizeof(char) * (bytes.st_size + 1));
    if (read(fd, map, bytes.st_size) == - 1)
        return (ERROR);
    map[bytes.st_size] = '\0';
    ret = checking_map(map);
    free(map);
    return (ret);
}

int error_handling(int ac, char **av, char *map)
{
    if (ac != 2)
        return (ERROR);
    if (av[1][0] == '-' && av[1][1] == 'h' && my_strlen(av[1]) == 2) {
        my_h();
        return (-42);
    }
    if (get_map(av, map) == ERROR)
        return (ERROR);
    return (SUCCESS);
}
