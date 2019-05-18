##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME	= my_sokoban

CC	= gcc

RM	= rm -f

SRCS	= ./src/my_sokoban.c \
	  ./src/displays/display_errors.c \
	  ./src/displays/display_map.c \
	  ./src/events/events.c \
	  ./src/events/lose_events.c \
	  ./src/moves/general_moves.c \
	  ./src/moves/move_boxs.c \
	  ./src/sets/set_colors.c \
	  ./src/sets/set_main_struct.c \
	  ./src/sets/set_map_size_coords.c \
	  ./src/sets/set_nb_chars.c 

OBJ	= $(SRCS:.c=.o)

LIBFLAG	= -L ./lib/my/ -lmy -lncurses

all: $(NAME)

$(NAME):
	cd lib/my && make re
	$(CC) $(SRCS) -o $(NAME) $(LIBFLAG)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re