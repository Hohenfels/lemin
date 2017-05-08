# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/03 13:46:38 by frenaud           #+#    #+#              #
#    Updated: 2017/03/24 14:23:27 by frenaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libft.a

SRC		=	ft_memset.c		ft_bzero.c		ft_memcpy.c						\
			ft_memccpy.c	ft_memmove.c	ft_memchr.c						\
			ft_memchr.c		ft_memcmp.c		ft_strlen.c						\
			ft_strdup.c		ft_strcpy.c		ft_strcat.c						\
			ft_strncat.c	ft_strlcat.c	ft_strchr.c						\
			ft_strrchr.c	ft_strstr.c		ft_strnstr.c					\
			ft_strcmp.c		ft_strncmp.c	ft_atoi.c						\
			ft_isalpha.c	ft_isdigit.c	ft_isalnum.c					\
			ft_isascii.c	ft_isprint.c	ft_toupper.c					\
			ft_tolower.c	ft_memalloc.c	ft_memdel.c 					\
			ft_strnew.c		ft_strdel.c		ft_strclr.c 					\
			ft_striter.c	ft_striteri.c	ft_strmap.c 					\
			ft_strmapi.c	ft_strequ.c		ft_strnequ.c					\
			ft_strsub.c		ft_strjoin.c	ft_strtrim.c					\
			ft_strsplit.c	ft_itoa.c		ft_putchar.c					\
			ft_putstr.c		ft_putendl.c	ft_putnbr.c						\
			ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c					\
			ft_putnbr_fd.c	ft_lstnew.c		ft_lstdelone.c					\
			ft_lstdel.c		ft_lstadd.c		ft_lstiter.c					\
			ft_lstmap.c		ft_islower.c	ft_isupper.c					\
			ft_isspace.c	ft_strncpy.c	ft_count_words.c					\
			ft_count_char.c	ft_strjoin_ultimate.c							\
			ft_putwchar.c	ft_putwstr.c									\
			get_next_line.c	ft_binlen.c		ft_charwlen.c					\
			ft_strwlen.c	ft_putnwchar.c	ft_putnwstr.c					\
			ft_atoi_nbase.c	ft_strlower.c	ft_strupper.c					\
			ft_itoa_base.c	ft_itoa_base_l.c	ft_itoa_base_ll.c			\
			ft_itoa_base_uint.c	check_flags.c	check_precision_int.c		\
			check_precision_str.c check_width.c	color_parser.c				\
			nblen.c		print_d.c	print_o.c	print_u.c	print_x.c		\
			print_xx.c	putnbr.c	conv_basics.c	conv_c.c		conv_d.c \
			conv_flags.c	conv_o.c	conv_p.c	conv_per.c				\
			conv_s.c	conv_u.c	conv_x.c	parsers.c	ft_printf.c		\
			ft_isnum.c	ft_atoi_long.c

OBJ		=	$(SRC:.c=.o)
FLAGS	=	-Werror -Wall -Wextra
YELLOW	=	\033[0;33m
WHITE	=	\033[0;97m

.PHONY : clean fclean re

all : $(NAME)

$(NAME) :
				@echo "$(YELLOW) _          _      _       		"
				@echo "$(YELLOW)| |   o    | |    | |    |   	"
				@echo "$(YELLOW)| |        | |    | |   _|_ 	"
				@echo "$(YELLOW)|/    |    |/ \_  |/     | 		"
				@echo "$(YELLOW)|__/  |_/   \_/   |__/   |_/	"
				@echo "$(YELLOW)                  |\        42	"
				@echo "$(YELLOW)                  |/            by frenaud"
				@echo "$(WHITE)Compiling ..."
				@gcc $(FLAGS) -c $(SRC) -I libft.h
				@ar rc $(NAME) $(OBJ)
				@ranlib $(NAME)
				@echo "Libft and index created"

clean :

	@/bin/rm -f $(OBJ)
	@echo "All objects removed"

fclean : clean

	@/bin/rm -f $(NAME)
	@echo "All files removed"

re : fclean all
