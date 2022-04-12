/*
** EPITECH PROJECT, 2022
** get_map.c
** File description:
** get_map
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "my_sokoban.h"
#include "my_macro.h"

int get_map(char **av, sokoban_t *soko)
{
    struct stat bytes;
    int fd = 0;

    stat(av[1], &bytes);
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return (ERROR);
    soko->map->map = malloc(sizeof(char) * (bytes.st_size + 1));
    if (read(fd, soko->map->map, bytes.st_size) == - 1)
        return (ERROR);
    soko->map->map[bytes.st_size] = '\0';
    return (SUCCESS);
}
