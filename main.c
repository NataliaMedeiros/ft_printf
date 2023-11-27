/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 08:46:56 by nmedeiro      #+#    #+#                 */
/*   Updated: 2023/11/27 18:32:45 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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
	char	buffer[1];

	copy_ft_printf_to_buffer(buffer, "%c\n", arg);
	my_len = ft_printf("My char print: %c", arg);
	ft_printf(" with len = %d\n", my_len);
	or_len = printf("My char print: %c", arg);
	printf(" with len = %d\n", or_len);
	assert(test_nb, (buffer[0] == arg));
	assert(test_nb + 1, (my_len == or_len));
}

// void	check_char(int test_number, int nb_args, char *res, char	*format, ...)
// {
// 	va_list	args;
// 	char	*str;
// 	int		len;
// 	char	temp;
// 	int		check;

// 	va_start(args, format);
// 	len = 2 * nb_args - 1;
// 	str = ft_calloc(len, sizeof(char));
// 	check = 1;
// 	for (int i = 0; i < len; i += 2)
// 	{
// 		temp = (char)va_arg(args, int);
// 		str[i] = temp;
// 	}
// 	assert(test_number, ft_strncmp(res, str, len));
// 	va_end(args);
// }
void	check_char_0(void)
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

void	check_char_2(void)
{
	int		my_len;
	int		or_len;
	char	*buffer;
	char	*str;

	str = "My char print: 'a', 'b', , 'd', 'e'";
	buffer = ft_calloc(sizeof(char), (ft_strlen(str) + 1));
	copy_ft_printf_to_buffer(buffer,
		"My char print: %c %c %c %c %c\n", 'a', 'b', 0, 'd', 'e');
	my_len = ft_printf("My char print: %c %c %c %c %c\n",
			'a', 'b', 0, 'd', 'e');
	or_len = printf("Or char print: %c %c %c %c %c\n", 'a', 'b', 0, 'd', 'e');
	assert(2, (ft_strncmp(buffer, str, ft_strlen(str))));
	assert(3, (my_len == or_len));
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

void	check_decimal(int test_nb, int nb)
{
	int		my_len;
	int		or_len;
	char	*buffer;

	buffer = ft_itoa(nb);
	my_len = ft_printf("%d", nb);
	ft_printf(" with len = %d\n", my_len);
	or_len = printf("%d", nb);
	printf(" with len = %d\n", or_len);
	//assert(test_nb, strcmp(buffer, nb));
	assert(test_nb + 1, (my_len == or_len));
}


int	main(void)
{
	ft_putchar_fd('\n', FD);
	check_char_0();
	ft_putchar_fd('\n', FD);
	check_char_2();
	ft_putchar_fd('\n', FD);
	check_unit_char(2,'5');
	ft_putchar_fd('\n', FD);
	check_unit_char(4,'B');
	ft_putchar_fd('\n', FD);
	check_unit_char(6, 0);
	ft_putchar_fd('\n', FD);
	check_string(8, "avocado");
	ft_putchar_fd('\n', FD);
	check_decimal(10, 1994);
	ft_putchar_fd('\n', FD);

	//int n = 0;

	// int ft_len = ft_printf("%d\n", 1994);
	// ft_printf("My decimal: %d\n", ft_len);
	// int len = printf("%d\n", 1994);
	// printf("Or decimal: %d\n\n", len);
	//ft_printf("My lower Hex: %x\n", -1);
	//printf("Or lower Hex: %x\n\n", -1);
	// ft_printf("My upper Hex: %X, %X, %X\n", 255, 166, 178);
	// printf("Or upper Hex: %X %X, %X\n\n", 255, 166, 178);
	// ft_printf("My integer: %i\n", 0x2A);
	// printf("Or integer: %i\n\n", 0x2A);
	//int ft_len = 
	//ft_printf("My ptr: %p\n", &n);
	//int len = printf("Or ptr: %p\n", &n);
	//ft_printf("ft_len = %d and len = %d\n", ft_len, len);

	// int len = ft_printf("%s\n", (char *)NULL);
	// printf("len %d", len);
	// ft_printf("My unsigned %u\n", UINT_MAX);
	// printf("Or unsigned %u\n\n", UINT_MAX);
	int i = 0;
	int ft_len = ft_printf("%i\n", i);
	int len = printf("%i\n", i);
	ft_printf("ft_len = %d and len = %d\n", ft_len, len);

	return (0);
}
