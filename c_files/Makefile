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

O_FILES = $(C_FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

SDL = $$(sdl-config --cflags --libs) -lSDL_image -lSDL_ttf -lSDL_gfx
SDL2 = '-lSDL2-2.0 -lSDL2_ttf'
MATH = -lm

LIB = $(SDL)

all: $(NAME)

$(NAME):
	gcc -c $(C_FILES) $(FLAGS) $(LIB)
	gcc -o $(NAME) $(O_FILES) $(FLAGS) $(LIB)

clean:
	rm -f $(O_FILES)

clean_swp:
	find . -name "*~" -o -name "#*#" -o -name ".*.swp" -delete -print

fclean: clean clean_swp
	rm -f $(NAME)

re: fclean all

noflags: fclean
	gcc -c $(C_FILES) $(LIB)
	gcc -o $(NAME) $(O_FILES) $(LIB)

noobj: re clean

noflags_noobj: noflags clean

open:
	vim +12 ../ino_files/*/*.ino ../py_files/*.py Makefile *.c *.h

exec:
	make noobj
	./$(NAME)

gadd: clean clean_swp
	git add -A

gcommit: gadd
	git commit -m "commit"

gpush: gcommit
	git push
