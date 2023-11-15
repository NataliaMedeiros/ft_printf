/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   assert.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 15:56:32 by natalia       #+#    #+#                 */
/*   Updated: 2023/11/15 14:03:56 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>
#include <stdio.h>

#define SET_COLOR_RED "\x1b[31m"
#define RESET_COLOR_RED "\x1b[0m"
#define SET_COLOR_GREEN "\x1b[32m"
#define RESET_COLOR_GREEN "\x1b[0m"

void	assert(int test_number, int condition)
{
	if (!(condition))
		ft_printf("%s%d:[failed]%s", SET_COLOR_RED, test_number, RESET_COLOR_RED);
	else
		ft_printf("%s%d:[OK] %s", SET_COLOR_GREEN, test_number, RESET_COLOR_GREEN);
}

// void	memory_assert(int test_number, int condition)
// {
// 	if (!(condition))
// 		printf("%s%d:[failed]%s", SET_COLOR_RED, test_number, RESET_COLOR_RED);
// 	else
// 		printf("%s%d: M[OK] %s", SET_COLOR_GREEN, test_number, RESET_COLOR_GREEN);
// }