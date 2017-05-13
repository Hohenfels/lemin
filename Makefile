# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/29 15:06:49 by frenaud           #+#    #+#              #
#    Updated: 2017/05/13 10:49:43 by frenaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEMIN = lem-in

SRC = 	./src/get_ants.c\
		./src/get_pipes.c\
		./src/get_rooms.c\
		./src/get_flag.c\
		./src/get_links.c\
		./src/utils.c\
		./src/error.c\

LEMIN_C = src/lemin.c

OBJ = $(SRC:.c=.o)

LEMIN_O = $(LEMIN_C:.c=.o)

INC = ./inc/lemin.h

LIB = libft/

GCC = GCC
FLAGS = -Wall -Werror -Wextra

.PHONY: clean fclean all re lib

all: lib $(LEMIN)

$(LEMIN): $(OBJ) $(LEMIN_O)
	 		@echo Compiling $(LEMIN)
			@$(GCC) $(FLAGS) -o $(LEMIN) $(LEMIN_C) $(OBJ) $(LIB)libft.a
$(OBJ): src/%.o : src/%.c
			@echo "$(LEMIN) >>> Update $^"
			@$(GCC) $(FLAGS) -c -I $(INC) $< -o $@
lib:
			@make -C $(LIB)
clean:
			@make -C $(LIB) clean
			@echo Cleaning obj...
			@rm -rf $(OBJ) $(LEMIN_O)
fclean: clean
			@make -C $(LIB) fclean
			@echo Cleaning repository...
			@rm -rf $(LEMIN)
re: fclean all
