/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmedeiro <nmedeiro@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 11:07:22 by nmedeiro      #+#    #+#                 */
/*   Updated: 2023/11/13 15:02:55 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_check_arg(va_list args, const char type)
{
	if (type == 'c')
	{
		ft_putchar_fd((va_arg(args, int)), 1);
	}
	else if (type == 's')
	{
		ft_putstr_fd(va_arg(args, char *), 1);
	}
	else if (type == 'd')
	{
		ft_putnbr_fd((va_arg(args, int)), 1);
	}
	else if (type == 'p')
	{
		
	}
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
				i++;
			}
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	return (0);
}

int	main(void)
{
	ft_printf("%s and 5 %d", "avocado", 855362);
	return (0);
}
