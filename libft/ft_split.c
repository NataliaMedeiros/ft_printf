/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmedeiro <nmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:19:25 by nmedeiro          #+#    #+#             */
/*   Updated: 2023/11/13 08:23:32 by nmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int		i;
	int		i_word;

	i = 0;
	i_word = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i])
			i_word++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (i_word);
}

char	**free_words(char **new_word, int i)
{
	while (i >= 0)
	{
		free (new_word[i]);
		i--;
	}
	free (new_word);
	return (new_word);
}

char	**filling_new_word(char **new_word, const char *s, char c)
{
	int	i;
	int	n;
	int	start;

	i = 0;
	n = 0;
	start = 0;
	while (s[n] != '\0')
	{
		while (s[n] && s[n] == c)
			n++;
		start = n;
		if (s[n] && s[n] != c)
		{
			while (s[n] != c && s[n] != '\0')
				n++;
			new_word[i] = ft_substr(s, start, (n - start));
			if (new_word[i] == NULL)
			{
				free_words(new_word, i);
				return (NULL);
			}
			i++;
		}
	}
	new_word[i] = NULL;
	return (new_word);
}

char	**ft_split(char const *s, char c)
{
	char	**new_word;

	if (!s)
		return (NULL);
	new_word = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!new_word)
		return (NULL);
	new_word = filling_new_word(new_word, s, c);
	return (new_word);
}
