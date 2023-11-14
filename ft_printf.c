/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:07:22 by nmedeiro          #+#    #+#             */
/*   Updated: 2023/11/14 18:10:31 by natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
# include <limits.h>


int	ft_check_arg(va_list args, const char type)
{
	if (type == 'c')
		ft_putchar_fd(((char)va_arg(args, int)), FD);
	else if (type == 's')
	{
		ft_putstr_fd(va_arg(args, char *), FD);
	}
	else if (type == 'd' || type == 'i')
		ft_putnbr_fd((va_arg(args, int)), FD);
	else if (type == 'u')
		ft_putunsigned(va_arg(args, unsigned int));
	else if (type == 'p')
		ft_putpointer(va_arg(args, unsigned long));
	else if (type == 'x')
		ft_puthex((va_arg(args, unsigned int)), type);
	else if (type == 'X')
		ft_puthex((va_arg(args, unsigned int)), type);
	return (0);
}

int	ft_printf(const	char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	if (!format)
		return (0);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
			{
				ft_check_arg(args, format[i + 1]);
				va_arg(args, int);
			}
			i++;
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	int	n;
	int	*ptr;

	n = 42;
	ptr = &n;
	ft_printf("My char: %c, %c, %c, %c, %c\n", 'a', 'b', 'c', 'd', 'e');
	printf("Or char: %c, %c, %c, %c, %c\n\n", 'a', 'b', 'c', 'd', 'e');
	ft_printf("My string: %s\n", "avocado");
	printf("Or string: %s\n\n", "avocado");
	ft_printf("My decimal: %d\n", 1994);
	printf("Or decimal: %d\n\n", 1994);
	ft_printf("My lower Hex: %x\n", 255);
	printf("Or lower Hex: %x\n\n", 255);
	ft_printf("My upper Hex: %X\n", 255);
	printf("Or upper Hex: %X\n\n", 255);
	ft_printf("My integer: %i\n", 0x2A);
	printf("Or integer: %i\n\n", 0x2A);
	ft_printf("My ptr: %p\n", ptr);
	printf("Or ptr: %p\n\n", ptr);
	ft_printf("My unsigned %u\n", UINT_MAX);
	printf("Or unsigned %u\n\n", UINT_MAX);
	return (0);
}
