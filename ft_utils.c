/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:14:40 by nmedeiro          #+#    #+#             */
/*   Updated: 2023/11/17 17:00:55 by natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	intlen_dec(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb *= -1;
		len = 1;
	}
	while (nb != 0)
	{
		nb /= 10;
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
	ft_putstr_fd(str, FD);
	return (ft_strlen(str));
}

int	ft_putnbr(int nb)
{
	if (nb == 0)
	{
		ft_putchar('0');
		return (0);
	}
	else
	{
		ft_putnbr_fd(nb, FD);
	}
	return (intlen_dec(nb));
}

int	ft_putunsigned(unsigned int n)
{
	unsigned int	nb;
	int				len;
	char			*str_n;

	nb = n;
	len = intlen_dec(nb);
	if (n == 0)
	{
		ft_putchar_fd('0', FD);
		return (1);
	}
	else
	{
		str_n = ft_calloc(len + 1, sizeof(char));
		str_n[len] = '\0';
		len--;
		while (nb > 0)
		{
			str_n[len] = nb % 10 + '0';
			nb /= 10;
			len--;
		}
		ft_putstr_fd(str_n, FD);
		len = ft_strlen(str_n);
		free (str_n);
	}
	return (len);
}
