/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:14:35 by nmedeiro          #+#    #+#             */
/*   Updated: 2023/11/14 18:32:53 by natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define FD 1

int	ft_puthex(unsigned int n, const char type);

int	ft_putpointer(unsigned long n);

int	ft_putunsigned(unsigned int n);

int	intlen_dec(unsigned int nb);

#endif
