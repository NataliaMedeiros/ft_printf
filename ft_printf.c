/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 11:07:22 by nmedeiro      #+#    #+#                 */
/*   Updated: 2023/11/15 09:40:09 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_check_arg(va_list args, const char type)
{
	if (type == 'c')
		return (ft_putchar(((char)va_arg(args, int))));
	else if (type == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr((va_arg(args, int))));
	else if (type == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (type == 'p')
		return ((va_arg(args, unsigned long)));
	else if (type == 'x')
		return ((va_arg(args, unsigned int)), type);
	else if (type == 'X')
		return (ft_puthex((va_arg(args, unsigned int)), type));
	return (0);
}

int	ft_printf(const	char *format, ...)
{
	va_list	args;
	int		i;
	int		total_len;

	i = 0;
	total_len = 0;
	if (!format)
		return (0);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
				total_len += ft_check_arg(args, format[i + 1]);
			i++;
		}
		else
			total_len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (total_len);
}
