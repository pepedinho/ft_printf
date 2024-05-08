/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:31:44 by itahri            #+#    #+#             */
/*   Updated: 2024/05/07 17:59:01 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nbr)
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

void	ft_putnbr_base(long long int nbr, char *base)
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

void	print_mem(void *ptr)
{
	unsigned long long int	addres_num;

	addres_num = (unsigned long long int)ptr;
	write(1, "0x", 2);
	ft_putnbr_base(addres_num, "0123456789abcdef");
}

void	check_type(const char *c, va_list args)
{
	char	car;

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
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	else if (*c == 'x')
		ft_putnbr_base(va_arg(args, long long int), "0123456789abcdef");
	else if (*c == 'X')
		ft_putnbr_base(va_arg(args, long long int), "0123456789ABCDEF");
	else if (*c == '%')
		write(1, "%%", 1);
}

int	check_flags(const char *c, va_list args)
{
	c++;
	if (*c == '0')
		return (zero_format(c, args));
	else if (*c == '+')
		return (plus_format(c, args));
	else
	{
		check_type(&c[0], args);
		return (1);
	}
}
