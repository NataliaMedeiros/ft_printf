/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:46:56 by nmedeiro          #+#    #+#             */
/*   Updated: 2024/01/12 13:59:40 by natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "printf.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>


#define SET_RED "\x1b[31m"
#define RESET_RED "\x1b[0m"

void	assert(int test_number, int condition)
{
	if (!(condition))
		ft_printf("\x1b[31m%d:[failed]\x1b[0m ", test_number);
	else
		ft_printf("\x1b[32m%d:[OK]\x1b[0m ", test_number);
}

/* the function checks both outputs and return 1 if they are the same and 0 if not */
/* fgetc is a standart c funtion that takes the next caracter from de file         */
/* EOF is defined in stdio.h and represents the End Of a File                      */
int	compare_files(const char *file1, const char *file2)
{
	FILE	*fd1;
	FILE	*fd2;
	int		result;
	int		c1;
	int		c2;

	fd1 = fopen(file1, "r");
	fd2 = fopen(file2, "r");
	c1 = fgetc(fd1);
	c2 = fgetc(fd2);
	result = 1;
	while (c1 != EOF && c2 != EOF)
	{
		if (c1 != c2)
		{
			result = 0;
			break ;
		}
		c1 = fgetc(fd1);
		c2 = fgetc(fd2);
	}
	return (result);
}

/* Function compare_outputs compares the output of your printf and the original printf  */
/* Function freopen directs the output to a especific file ir to the terminal           */
int	compare_outputs(int test_number, const char *format, ...)
{
	va_list	args_original;
	va_list	args_custom;
	int		res_original;
	int		res_custom;

	freopen("output.txt", "w", stdout);
	va_start(args_original, format);
	res_original = printf(format, args_original);
	va_end(args_original);
	freopen("my_output.txt", "w", stdout);
	va_start(args_custom, format);
	res_custom = ft_printf(format, args_custom);
	va_end(args_custom);
	freopen("/dev/tty", "w", stdout);
	assert(test_number, ((res_custom == res_original)
			&& (compare_files("output.txt", "my_output.txt")) == 1));
	return (0);
}

void	test_char(void)
{
	printf("Format c: ");
	compare_outputs(1, "%c", 'c');
	compare_outputs(2, "%c%c%c%c%c%c%c%c%c%c", 'a', 'b', 'c', 'd',
		'e', 'f', 'g', 'h', 'i', 'j');
	compare_outputs(3, "%c", '1');
	compare_outputs(4, "%s %s %s %s %s %s %s %s %s %s", '1', '2', '3', '4', '5',
		'6', '7', '8', '9', '0');
	compare_outputs(5, "Char print: %c %c %c %c %c\n", 'a', 'b', 0, 'd', 'e');
}

void	test_string(void)
{
	printf("Format s: ");
	compare_outputs(3, "%s", "Hello, World!");
	//compare_outputs(4, "Fruits: %s, %s, %s, %s, %s and %s", "avocado",
	//	"banana", "carrot", "kiwi", "grape", "passion fruit");
}

void	test_d(void)
{
	printf("Format d: ");
	compare_outputs(1, "%d", 0);
	compare_outputs(2, "%d", -1);
	compare_outputs(3, "%d", 42);
	compare_outputs(4, "%d", -42);
	compare_outputs(5, "%d", 102);
	compare_outputs(6, "%d", -102);
	compare_outputs(7, "%d", 1024);
	compare_outputs(8, "%d", -1024);
	compare_outputs(9, "%d", INT_MAX);
	compare_outputs(10, "%d", INT_MIN);
	compare_outputs(11, "%d", LONG_MAX);
	compare_outputs(12, "%d", LONG_MIN);
	compare_outputs(13, "%d", -10000000);
	compare_outputs(14, "%d", 10000000);
	compare_outputs(15, "%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
		0, -1, 42, -42, 102, -102, 1024, -1024, INT_MAX, INT_MIN, LONG_MAX, LONG_MIN);
}

void	test_i(void)
{
	printf("Format i: ");
	compare_outputs(1, "%i", 0);
	compare_outputs(2, "%i", -1);
	compare_outputs(3, "%i", 42);
	compare_outputs(4, "%i", -42);
	compare_outputs(5, "%i", 102);
	compare_outputs(6, "%i", -102);
	compare_outputs(7, "%i", 1024);
	compare_outputs(8, "%i", -1024);
	compare_outputs(9, "%i", INT_MAX);
	compare_outputs(10, "%i", INT_MIN);
	compare_outputs(11, "%i", LONG_MAX);
	compare_outputs(12, "%i", LONG_MIN);
	compare_outputs(13, "%i", -10000000);
	compare_outputs(14, "%i", 10000000);
	compare_outputs(15, "%i, %i, %i, %i, %i, %i, %i, %i, %i, %i, %i, %i, %i, %i",
		0, -1, 42, -42, 102, -102, 1024, -1024, INT_MAX, INT_MIN, LONG_MAX, LONG_MIN);
}

void	test_u(void)
{
	printf("Format u: ");
	compare_outputs(1, "%u", 0);
	compare_outputs(2, "%u", -1);
	compare_outputs(3, "%u", 42);
	compare_outputs(4, "%u", -42);
	compare_outputs(5, "%u", 102);
	compare_outputs(6, "%u", -102);
	compare_outputs(7, "%u", 1024);
	compare_outputs(8, "%u", -1024);
	compare_outputs(9, "%u", INT_MAX);
	compare_outputs(10, "%u", INT_MIN);
	compare_outputs(11, "%u", LONG_MAX);
	compare_outputs(12, "%u", LONG_MIN);
	compare_outputs(13, "%u", -10000000);
	compare_outputs(14, "%u", 10000000);
	compare_outputs(15, "%u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u",
		0, -1, 42, -42, 102, -102, 1024, -1024, INT_MAX, INT_MIN, LONG_MAX, LONG_MIN);
}

void	test_p(void)
{
	printf("Format p: ");
	compare_outputs(1, "%p", 0);
	compare_outputs(2, "%p", -1);
	compare_outputs(3, "%p", 42);
	compare_outputs(4, "%p", -42);
	compare_outputs(5, "%p", 102);
	compare_outputs(6, "%p", -102);
	compare_outputs(7, "%p", 1024);
	compare_outputs(8, "%p", -1024);
	compare_outputs(9, "%p", INT_MAX);
	compare_outputs(10, "%p", INT_MIN);
	compare_outputs(11, "%p", LONG_MAX);
	compare_outputs(12, "%p", LONG_MIN);
	compare_outputs(13, "%p", -10000000);
	compare_outputs(14, "%p", 10000000);
	compare_outputs(15, "%p, %p, %p, %p, %p, %p, %p, %p, %p, %p",
		0, -1, 42, -42, 102, -102, 1024, -1024);
}

void	test_x(void)
{
	printf("Format x: ");
	compare_outputs(1, "%x", 0);
	compare_outputs(2, "%x", -1);
	compare_outputs(3, "%x", 42);
	compare_outputs(4, "%x", -42);
	compare_outputs(5, "%x", 102);
	compare_outputs(6, "%x", -102);
	compare_outputs(7, "%x", 1024);
	compare_outputs(8, "%x", -1024);
	compare_outputs(9, "%x", INT_MAX);
	compare_outputs(10, "%x", INT_MIN);
	compare_outputs(11, "%x", LONG_MAX);
	compare_outputs(12, "%x", LONG_MIN);
	compare_outputs(13, "%x", -10000000);
	compare_outputs(14, "%x", 10000000);
	compare_outputs(15, "%x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x",
		0, -1, 42, -42, 102, -102, 1024, -1024, INT_MAX, INT_MIN, LONG_MAX, LONG_MIN);
}

void	test_upperx(void)
{
	printf("Format X: ");
	compare_outputs(1, "%X", 0);
	compare_outputs(2, "%X", -1);
	compare_outputs(3, "%X", 42);
	compare_outputs(4, "%X", -42);
	compare_outputs(5, "%X", 102);
	compare_outputs(6, "%X", -102);
	compare_outputs(7, "%X", 1024);
	compare_outputs(8, "%X", -1024);
	compare_outputs(9, "%X", INT_MAX);
	compare_outputs(10, "%X", INT_MIN);
	compare_outputs(11, "%X", LONG_MAX);
	compare_outputs(12, "%X", LONG_MIN);
	compare_outputs(13, "%X", -10000000);
	compare_outputs(14, "%X", 10000000);
	compare_outputs(15, "%X, %X, %X, %X, %X, %X, %X, %X, %X, %X, %X, %X, %X, %X",
		0, -1, 42, -42, 102, -102, 1024, -1024, INT_MAX, INT_MIN, LONG_MAX, LONG_MIN);
}

void	test_multiplo(void)
{
	printf("Format multiplo: ");
	compare_outputs(1, "%%");
	compare_outputs(2, "%%%%");
	compare_outputs(3, "%% %%");
	compare_outputs(4, "%% %% %%");
	compare_outputs(5, "%%%%%%");
	compare_outputs(2, "%%%c%%", 'c');
	compare_outputs(2, "%s%%%%", "test");

}

int	main(void)
{
	test_char();
	test_string();
	test_d();
	test_i();
	test_u();
	test_p();
	test_x();
	test_upperx();
	test_multiplo();
	return (0);
}

