#include "libftprintf.h"

int	intlen_hex(int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb /= 16;
		len++;
	}
	len--;
	return (len);
}

int	intlen_dec(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	len--;
	return (len);
}

int	ft_puthex(unsigned int n, const char type)
{
	int				len;
	char			*str_n;
	char			*hex_base;

	len = intlen_hex(n) + 1;
	if (type == 'x')
		hex_base = "0123456789abcdef";
	else if (type == 'X')
		hex_base = "0123456789ABCDEF";
	if (n == 0)
		ft_putchar_fd('0', FD);
	else
	{
		str_n = ft_calloc(len, sizeof(char));
		str_n[len] = '\0';
		len -= 1;
		while (n > 0)
		{
			str_n[len] = hex_base[n % 16];
			n /= 16;
			len--;
		}
		ft_putstr_fd(str_n, FD);
	}
	return (ft_strlen(str_n));
}

int	ft_putpointer(unsigned long n)
{
	unsigned long	nb;
	int				len;
	char			*str_n;
	char			*hex_base;

	nb = n;
	len = intlen_hex(n) + 4;
	hex_base = "0123456789abcdef";
	if (n == 0)
	{
		ft_putstr_fd("0x0", FD);
		return (3);
	}
	str_n = ft_calloc(len, sizeof(char));
	str_n[0] = '0';
	str_n[1] = 'x';
	str_n[len] = '\0';
	while (n > 0)
	{
		str_n[len-1] = hex_base[n % 16];
		n /= 16;
		len--;
	}
	ft_putstr_fd(str_n, FD);
	return (ft_strlen(str_n));
}

int	ft_putunsigned(unsigned int n)
{
	unsigned int	nb;
	int				len;
	char			*str_n;

	nb = n;
	len = intlen_dec(nb) + 1;
	if (n == 0)
	{
		ft_putchar_fd('0', FD);
	}
	else
	{
		str_n = ft_calloc(len, sizeof(char));
		str_n[len] = '\0';
		len--;
		while (nb > 0)
		{
			str_n[len] = nb % 10 + '0';
			nb /= 10;
			len--;
		}
		ft_putstr_fd(str_n, FD);
	}
	return (ft_strlen(str_n));
}
