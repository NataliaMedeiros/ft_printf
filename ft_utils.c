/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 09:14:40 by nmedeiro      #+#    #+#                 */
/*   Updated: 2023/11/27 18:20:32 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	intlen(unsigned long nb, int base)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb /= base;
		len++;
	}
	return (len);
}

int	ft_putchar(int c)
{
	ft_putchar_fd(c, FD);
	return (1);
}

int	ft_putstr(char *str)
{
	if (str == NULL)
		str = "(null)";
	ft_putstr_fd(str, FD);
	return (ft_strlen(str));
}

int	ft_putnbr(int nb)
{
	char	*nb_char;
	int		len;

	nb_char = ft_itoa(nb);
	len = ft_putstr(nb_char);
	free(nb_char);
	return (len);
}

int	ft_putunsigned(unsigned int n)
{
	unsigned int	nb;
	int				len;
	char			*str_n;

	nb = n;
	len = intlen(nb, 10);
	if (n == 0)
		return (ft_putchar('0'));
	else
	{
		str_n = ft_calloc(len + 1, sizeof(char));
		while (nb > 0)
		{
			str_n[--len] = nb % 10 + '0';
			nb /= 10;
		}
		len = ft_putstr(str_n);
		free (str_n);
	}
	return (len);
}
