# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/01 19:44:41 by tnicolas          #+#    #+#              #
#    Updated: 2017/09/01 19:45:53 by tnicolas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bras_c

C_FILES = main.c \
		  event.c

OBJ = $(C_FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

SDL = $$(sdl-config --cflags --libs) -lSDL_image -lSDL_ttf -lSDL_gfx
SDL2 = '-lSDL2-2.0 -lSDL2_ttf'
MATH = -lm

LIB = $(SDL)

all: $(NAME)

$(NAME):
	gcc -c $(C_FILES) $(FLAGS) $(LIB)
	gcc -o $(NAME) $(OBJ) $(FLAGS) $(LIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

noflags: fclean
	gcc -c $(C_FILES) $(LIB)
	gcc -o $(NAME) $(OBJ) $(LIB)

noobj: re clean

noflags_noobj: noflags clean

gadd:
	git add -A

gcommit: gadd
	git commit -m "commit"

gpush: gcommit
	git push
