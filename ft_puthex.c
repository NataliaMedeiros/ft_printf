/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 14:11:30 by nmedeiro      #+#    #+#                 */
/*   Updated: 2023/11/22 11:48:47 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	intlen_hex(unsigned long nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

int	ft_puthex(unsigned int n, const char type)
{
	int				len;
	char			*str_n;
	char			*hex_base;

	len = intlen_hex(n);
	if (type == 'x')
		hex_base = "0123456789abcdef";
	else if (type == 'X')
		hex_base = "0123456789ABCDEF";
	if (n == 0)
		len = ft_putchar('0');
	else
	{
		str_n = ft_calloc(len + 1, sizeof(char));
		str_n[len] = '\0';
		while (n > 0)
		{
			str_n[--len] = hex_base[n % 16];
			n /= 16;
		}
		len = ft_putstr(str_n);
		free (str_n);
	}
	return (len);
}

int	ft_putpointer(unsigned long n)
{
	int				len;
	char			*str_n;
	char			*hex_base;

	len = intlen_hex(n) + 3;
	hex_base = "0123456789abcdef";
	if (n == 0)
		len = ft_putstr("(nil)");
	else
	{
		str_n = ft_calloc(len, sizeof(char));
		str_n[0] = '0';
		str_n[1] = 'x';
		str_n[len - 1] = '\0';
		while (n > 0)
		{
			str_n[--len - 1] = hex_base[n % 16];
			n /= 16;
		}
		len = ft_putstr(str_n);
		free (str_n);
	}
	return (len);
}
