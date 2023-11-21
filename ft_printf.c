/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:07:22 by nmedeiro          #+#    #+#             */
/*   Updated: 2023/11/21 14:27:29 by natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_arg(va_list args, const char type)
{
	//printf("Cheguei no ft_check_arg como %c\n", type);
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
		//printf("Entrei no esle if correto e meu valor %d and %c\n", va_arg(args, unsigned int), type);
		return (ft_puthex((va_arg(args, unsigned long)), type));
	else if (type == 'X')
		return (ft_puthex((va_arg(args, unsigned long)), type));
	else if (type == '%')
		return (ft_putchar('%'));
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
				va_arg(args, int); //at my computer this line is necessary
			i++;
		}
		else
			total_len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	//free (args);
	return (total_len);
}
