# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: natalia <natalia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 11:10:51 by nmedeiro          #+#    #+#              #
#    Updated: 2023/11/21 14:49:34 by natalia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft/libft.a

FILES = ft_printf \
		ft_puthex \
		ft_utils \

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
	@echo "Compiling ..."
	@make -C $(LIBFTDIR)
	@echo "Compiled ✅ $(LIBFT)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFTDIR)

$(NAME): $(LIBFT) $(OFILES)
	@cp $(LIBFT) $(NAME)
	@ar -rc $(NAME) $(OFILES) ${LIBFT}
	@echo "Compiled ✅ $^"

#bonus: $(OBONUS)
#	ar -rc $(NAME) $(OBONUS)

clean:
	@rm -f $(OFILES)

fclean: clean
	@cd libft && $(MAKE) fclean 1> /dev/null
	@rm -f $(NAME)
	@rm -f $(OBONUS)
	@echo
	@echo "Cleansed ✅"

re: fclean all

.PHONY: all, clean, fclean, re
