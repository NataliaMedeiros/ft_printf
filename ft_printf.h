/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:14:35 by nmedeiro          #+#    #+#             */
/*   Updated: 2023/11/21 14:27:38 by natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define FD 1

int	ft_printf(const	char *format, ...);

int	ft_puthex(unsigned long n, const char type);

int	ft_putpointer(unsigned long n);

int	ft_putunsigned(unsigned int n);

int	ft_putchar(int c);

int	ft_putstr(char *str);

int	ft_putnbr(int nb);

#endif
