/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:59:19 by itahri            #+#    #+#             */
/*   Updated: 2024/05/06 17:21:03 by itahri           ###   ########.fr       */
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

static void ft_putnbr_base(unsigned long long int nbr, char *base)
{
	char	char_nbr;

	if (nbr >= ft_strlen(base))
		ft_putnbr_base(nbr / ft_strlen(base), base);
	char_nbr = base[nbr % ft_strlen(base)];
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
	else if (*c == 'd')
		ft_putnbr(va_arg(args, int));
	else if (*c == 'p')
		print_mem(va_arg(args, void *));		
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
	int i = 123;
	char str[] = "je m'appel";
	char car = 't';
	printf("original :\nvariable 1 : %s\nvariable 2 : %d\nvariable 3 : %c\naddress de (i) : %p\n", str, i, car, &i);
	ft_prinft("ft :\nvariable 1 : %s\nvariable 2 : %d\nvariable 3 : %c\naddress de (i) : %p\n", str, i, car, &i);
	return 0;
}
