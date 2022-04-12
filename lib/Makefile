##
## EPITECH PROJECT, 2021
## makefile
## File description:
## Compil programme for project my_printf
##

SRC	=	my_strlen.c	\
		my_str_to_word_array.c	\
		put_str_to_word_array.c	\
		my_array_len.c	\
		my_arraycpy.c	\
		my_free_array.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CPPFLAGS = -Wall -Wextra

CPPFLAGS = -I../includes

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY:	all clean fclean re
