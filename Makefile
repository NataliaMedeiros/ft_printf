# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: natalia <natalia@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2023/11/13 11:10:51 by nmedeiro      #+#    #+#                  #
#    Updated: 2023/11/15 08:43:06 by nmedeiro      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft/libft.a

FILES = ft_printf \
		ft_puthex \

#Bonus =

CFILES = $(FILES:%=%.c)
#CBONUS = $(Bonus:%=%.c)

OFILES = $(CFILES:%.c=%.o)
#OBONUS = $(CBONUS:%.c=%.o)


CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft

all: $(NAME)

$(LIBFT):
	make -C $(LIBFTDIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OFILES)
#	cd libft && $(MAKE)
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
