#!/bin/bash

BOLD=$(tput bold)
RESET=$(tput sgr0)

rm -rf exec
mkdir exec
make re

cc -Wall -Werror -Wextra \
	main.c \
	ft_printf.c \
	ft_puthex.c \
	ft_utils.c \
	-L. -Llibft -lft \
	-L. -I -lftprintf \
	-o exec/ft_printf

#	echo "Compiling file ${BOLD} ft_printf ${RESET}"
if [ -f exec/ft_printf ]; then
	echo "Compilation successful for file ft_printf. Starting tests"
	./exec/ft_printf
else
	echo "Compilation failed  for file ft_printf."
fi

make fclean
