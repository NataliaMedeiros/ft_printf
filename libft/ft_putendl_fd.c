/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmedeiro <nmedeiro@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 08:18:51 by nmedeiro      #+#    #+#                 */
/*   Updated: 2023/11/22 14:43:17 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
