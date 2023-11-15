# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: natalia <natalia@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2023/11/13 11:10:51 by nmedeiro      #+#    #+#                  #
#    Updated: 2023/11/15 13:54:25 by nmedeiro      ########   odam.nl          #
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
	@echo "Compiling ..."
	@make -C $(LIBFTDIR) 1> /dev/null
	@echo "Compiled ✅ $(LIBFT)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OFILES)
#	cd libft && $(MAKE)
	@ar -rc $(NAME) $(OFILES)
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
