/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmedeiro <nmedeiro@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 18:02:50 by nmedeiro      #+#    #+#                 */
/*   Updated: 2023/11/22 15:37:21 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*new;
	size_t	total;

	total = nmemb * size;
	if (nmemb && (total / nmemb) != size)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	new = malloc(total);
	if (new == NULL)
		return (NULL);
	ft_bzero(new, total);
	return (new);
}
