/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:59:19 by itahri            #+#    #+#             */
/*   Updated: 2024/05/06 23:14:59 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


static void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

static void	ft_putnbr(int nbr)
{
	char	char_nbr;

	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ; 
	}

	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	char_nbr = (nbr % 10) + '0';
	write(1, &char_nbr, 1);
}

static void ft_putnbr_base(long long int nbr, char *base)
{
	char	char_nbr;
	int		base_len;

	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
	}
	nbr = (unsigned long long)nbr;
	if (nbr >= base_len)
		ft_putnbr_base(nbr / base_len, base);
	char_nbr = base[nbr % base_len];
	write(1, &char_nbr, 1);
}


static void	print_mem(void *ptr)
{
	unsigned long long int	addres_num = (unsigned long long int)ptr; 
	
	write(1, "0x", 2);
	ft_putnbr_base(addres_num, "0123456789abcdef");
}


static void	check_type(const char *c, va_list args)
{
	char	car;

	c++;
	if (*c == 'c')
	{
		car = va_arg(args, int);
		write(1, &car, 1);
	}
	else if (*c == 's')
		ft_putstr(va_arg(args, const char *));
	else if (*c == 'd' || *c == 'i')
		ft_putnbr(va_arg(args, int));
	else if (*c == 'p')
		print_mem(va_arg(args, void *));
	else if (*c == 'u')
		ft_putnbr_base(va_arg(args,unsigned int), "0123456789");
	else if (*c == 'x')
		ft_putnbr_base(va_arg(args, long long int), "0123456789abcdef");
	else if (*c == 'X')
		ft_putnbr_base(va_arg(args, long long int), "0123456789ABCDEF");
	else if (*c == '%')
		write(1, "%%", 1);
}

int	ft_prinft(const char *format, ...)
{
	va_list		args;
	int			i;

	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			check_type(&format[i], args);
			i ++;
		}
		else
			write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return 1;
}

int main()
{
	int e = 010;
	int i = +214748364;
	unsigned int j = -2147483648;
	int hex = -2147483648;
	char str[] = "je m'appel";
	char car = 't';
	printf("original :\nVariable 1 : %s\nVariable 2 : %d\nVariable 3 : %i\nVariable 4 : %c\nAddress de (i) : %p\nVariable 5 : %u\nVariable 6 : %x\nVariable 6 : %X%%\ntest : %04d", str, i, e, car, &i, j, hex, hex, 10);
	ft_prinft("ft :\nVariable 1 : %s\nVariable 2 : %d\nVariable 3 : %i\nVariable 4 : %c\nAddress de (i) : %p\nVariable 5 : %u\nVariable 6 : %x\nVariable 6 : %X%%\n", str, i, e, car, &i, j, hex, hex);
	return 0;
}
