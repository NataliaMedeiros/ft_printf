# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: natalia <natalia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 17:19:02 by natalia           #+#    #+#              #
#    Updated: 2023/11/02 11:22:01 by natalia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Library = libft
Files = ft_isalpha \
		ft_isascii \
		ft_isdigit \
		ft_isprint \
		ft_strchr \
		ft_strlcat \
		ft_strlcpy \
		ft_strrchr \
		ft_strlen \
		ft_memset \
		ft_bzero \
		ft_atoi \
		ft_isalnum \
		ft_strdup \
		ft_tolower \
		ft_toupper \
		ft_memchr \
		ft_memcmp \
		ft_strncmp \
		ft_strnstr \
		ft_memcpy \
		ft_memmove \
		ft_calloc \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_split \
		ft_itoa \
		ft_strmapi \
		ft_striteri \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \

Bonus =	ft_lstnew \
		ft_lstadd_front \
		ft_lstsize \
		ft_lstlast \
		ft_lstadd_back \
		ft_lstdelone \
		ft_lstclear \
		ft_lstiter \
		ft_lstmap \

CFILES = $(Files:%=%.c)
CBONUS = $(Bonus:%=%.c)

OFILES = $(CFILES:%.c=%.o)
OBONUS = $(CBONUS:%.c=%.o)
NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OFILES)
	ar -rc $(NAME) $(OFILES)

bonus: $(OBONUS)
	ar -rc $(NAME) $(OBONUS)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)
	rm -f $(OBONUS)

re: fclean all

.PHONY: all, clean, fclean, re
