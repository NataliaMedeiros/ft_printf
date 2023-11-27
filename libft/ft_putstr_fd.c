/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmedeiro <nmedeiro@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 08:19:08 by nmedeiro      #+#    #+#                 */
/*   Updated: 2023/11/27 14:40:02 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write (fd, s, strlen(s));
}
