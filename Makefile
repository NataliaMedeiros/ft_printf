# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: natalia <natalia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 11:10:51 by nmedeiro          #+#    #+#              #
#    Updated: 2023/11/14 13:32:45 by natalia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft/libft.a

FILES = ft_printf \

#Bonus =

CFILES = $(FILES:%=%.c)
#CBONUS = $(Bonus:%=%.c)

OFILES = $(CFILES:%.c=%.o)
#OBONUS = $(CBONUS:%.c=%.o)


CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OFILES)
	cd libft && $(MAKE)
	ar -rc $(NAME) $(OFILES)

#bonus: $(OBONUS)
#	ar -rc $(NAME) $(OBONUS)

clean:
	rm -f $(OFILES)

fclean: clean
	cd libft && $(MAKE) fclean
	rm -f $(NAME)
	rm -f $(OBONUS)

re: fclean all

.PHONY: all, clean, fclean, re
