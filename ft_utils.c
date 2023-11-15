/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmedeiro <nmedeiro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 09:14:40 by nmedeiro      #+#    #+#                 */
/*   Updated: 2023/11/15 15:13:40 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	intlen_dec(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	len--;
	return (len);
}

int	ft_putchar(int c)
{
	ft_putchar_fd(c, FD);
	return (1);
}

int	ft_putstr(char *str)
{
	ft_putstr_fd(str, FD);
	return (ft_strlen(str));
}

int	ft_putnbr(int nb)
{
	ft_putnbr_fd(nb, FD);
	return (intlen_dec(nb));
}

int	ft_putunsigned(unsigned int n)
{
	unsigned int	nb;
	int				len;
	char			*str_n;

	nb = n;
	len = intlen_dec(nb) + 1;
	if (n == 0)
	{
		ft_putchar_fd('0', FD);
	}
	else
	{
		str_n = ft_calloc(len, sizeof(char));
		str_n[len] = '\0';
		len--;
		while (nb > 0)
		{
			str_n[len] = nb % 10 + '0';
			nb /= 10;
			len--;
		}
		ft_putstr_fd(str_n, FD);
	}
	return (ft_strlen(str_n));
}
