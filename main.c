/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmedeiro <nmedeiro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 08:46:56 by nmedeiro      #+#    #+#                 */
/*   Updated: 2023/11/15 08:47:35 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <limits.h>

int	main(void)
{
	// int	n;
	// int	*ptr;

	// n = 42;
	// ptr = &n;
	// ft_printf("My char: %c, %c, %c, %c, %c\n", 'a', 'b', 'c', 'd', 'e');
	// printf("Or char: %c, %c, %c, %c, %c\n\n", 'a', 'b', 'c', 'd', 'e');
	// ft_printf("My string: %s\n", "avocado");
	// printf("Or string: %s\n\n", "avocado");
	ft_printf("My decimal: %d\n", 1994);
	printf("Or decimal: %d\n\n", 1994);
	// ft_printf("My lower Hex: %x\n", 255);
	// printf("Or lower Hex: %x\n\n", 255);
	// ft_printf("My upper Hex: %X, %X, %X\n", 255, 166, 178);
	// printf("Or upper Hex: %X %X, %X\n\n", 255, 166, 178);
	// ft_printf("My integer: %i\n", 0x2A);
	// printf("Or integer: %i\n\n", 0x2A);
	// ft_printf("My ptr: %p\n", ptr);
	// printf("Or ptr: %p\n\n", ptr);
	// ft_printf("My unsigned %u\n", UINT_MAX);
	// printf("Or unsigned %u\n\n", UINT_MAX);
	return (0);
}
