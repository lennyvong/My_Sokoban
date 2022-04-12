##
## EPITECH PROJECT, 2022
## Makefile_bs
## File description:
## Makefile
##

CC	=	gcc

SRC	=	sokoban_files/sokoban.c	\
		sokoban_files/error.c	\
		sokoban_files/some_get/get_map.c	\
		sokoban_files/some_get/find_player.c	\
		sokoban_files/deplacements/player.c	\
		sokoban_files/deplacements/boxes.c	\
		sokoban_files/deplacements/targets.c	\
		sokoban_files/main_soko.c	\
		sokoban_files/map_actions/map_actions.c	\
		sokoban_files/structures/set_struct.c	\
		sokoban_files/structures/get_targets.c	\
		sokoban_files/end_game.c	\
		sokoban_files/free/my_free_struct.c	\
		sokoban_files/my_h.c

OBJ	=	$(SRC:.c=.o)

CFLAGS = -Wall -Wextra

CPPFLAGS	=	-L./lib -lmy -I./includes -lncurses

NAME	=	my_sokoban

all: $(NAME)

$(NAME):	$(OBJ)
	make re -C lib/
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
	make clean -C lib/
	rm -f $(OBJ)

fclean:	clean
	make fclean -C lib/
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
