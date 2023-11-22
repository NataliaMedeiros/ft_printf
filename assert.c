/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:56:32 by natalia           #+#    #+#             */
/*   Updated: 2023/11/17 15:08:31 by natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

#define SET_RED "\x1b[31m"
#define RESET_RED "\x1b[0m"
#define SET_GREEN "\x1b[32m"
#define RESET_GREEN "\x1b[0m"

void	assert(int test_number, int condition)
{
	if (!(condition))
		ft_printf("%s%d:[failed]%s", SET_RED, test_number, RESET_RED);
	else
		ft_printf("%s%d:[OK] %s", SET_GREEN, test_number, RESET_GREEN);
}


tetest
