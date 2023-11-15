/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmedeiro <nmedeiro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 08:46:56 by nmedeiro      #+#    #+#                 */
/*   Updated: 2023/11/15 15:08:36 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <limits.h>

void	assert(int test_number, int condition);

void	copy_ft_printf_to_buffer(char *buffer, const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	vsprintf(buffer, format, args);
	va_end(args);
}

void	check_unit_char(int test_nb, char arg)
{
	int		my_len;
	int		or_len;
	char	buffer[2];

	copy_ft_printf_to_buffer(buffer, "%c\n", arg);
	my_len = ft_printf("My char print: %c", arg);
	ft_printf(" with len = %d\n", my_len);
	or_len = printf("Or char print: %c", arg);
	printf(" with len = %d\n", or_len);
	assert(test_nb, strcmp(buffer, &arg));
	assert(test_nb + 1, (my_len == or_len));
}

void	check_char(void)
{
	int		my_len;
	int		or_len;
	char	*buffer;
	char	*str;

	str = "My char print: 'a', 'b', 'c', 'd', 'e'";
	buffer = ft_calloc(sizeof(char), (ft_strlen(str) + 1));
	copy_ft_printf_to_buffer(buffer,
		"My char print: %c %c %c %c %c\n", 'a', 'b', 'c', 'd', 'e');
	my_len = ft_printf("My char print: %c %c %c %c %c\n",
			'a', 'b', 'c', 'd', 'e');
	or_len = printf("Or char print: %c %c %c %c %c\n", 'a', 'b', 'c', 'd', 'e');
	assert(0, (ft_strncmp(buffer, str, ft_strlen(str))));
	assert(1, (my_len == or_len));
}

void	check_string(int test_nb, char *str)
{
	int		my_len;
	int		or_len;
	char	buffer[2];

	copy_ft_printf_to_buffer(buffer, "%s\n", str);
	my_len = ft_printf("My string print: %s", str);
	ft_printf(" with len = %d\n", my_len);
	or_len = printf("Or string print: %s", str);
	printf(" with len = %d\n", or_len);
	assert(test_nb, strcmp(buffer, str));
	assert(test_nb + 1, (my_len == or_len));
}

int	main(void)
{
	ft_putchar_fd('\n', 1);
	/* test 0 and 1*/
	check_char();
	ft_putchar_fd('\n', 1);
	/* test 2 and 3*/
	check_unit_char(2,'5');
	ft_putchar_fd('\n', 1);
	/* test 4 and 5*/
	check_unit_char(4,'B');
	ft_putchar_fd('\n', 1);
	// int	n;
	// int	*ptr;


	// n = 42;
	// ptr = &n;
	check_string(6, "avocado");
	
	ft_printf("My string");
	//printf("Or string: %s\n\n", "avocado");
	// int ft_len = ft_printf("%d\n", 1994);
	// ft_printf("My decimal: %d\n", ft_len);
	// int len = printf("%d\n", 1994);
	// printf("Or decimal: %d\n\n", len);
	// ft_printf("My lower Hex: %x\n", 255);
	// printf("Or lower Hex: %x\n\n", 255);
	// ft_printf("My upper Hex: %X, %X, %X\n", 255, 166, 178);
	// printf("Or upper Hex: %X %X, %X\n\n", 255, 166, 178);
	// ft_printf("My integer: %i\n", 0x2A);
	// printf("Or integer: %i\n\n", 0x2A);
	// ft_printf("My ptr: %p\n", ptr);
	// printf("Or ptr: %p\n\n", ptr);
	// ft_printf("My unsigned %u\n", UINT_MAX);
	// printf("Or unsigned %u\n\n", UINT_MAX);
	return (0);
}
