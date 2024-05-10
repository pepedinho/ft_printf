/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:45:31 by itahri            #+#    #+#             */
/*   Updated: 2024/05/10 14:06:25 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	hasht_format(const char *c, va_list args)
{
	c++;
	if (*c == 'x')
	{
		write(1, "0x", 2);
		ft_putnbr_base(va_arg(args, long long int), "0123456789abcdef");
	}
	else if (*c == 'X')
	{
		write(1, "0X", 2);
		ft_putnbr_base(va_arg(args, long long int), "0123456789ABCDEF");
	}
	return (2);
}

int	space_format(const char *c, va_list args)
{
	int	arg;

	c++;
	if (*c == 'd' || *c == 'i')
	{
		arg = va_arg(args, int);
		if (arg < 0)
			ft_putnbr(arg);
		else
		{
			write(1, " ", 1);
			ft_putnbr(arg);
		}
	}
	return (2);
}

int	check_digit(const char *c, char *digit)
{
	int	i;

	i = 0;
	while (digit[i])
	{
		if (digit[i] == *c)
			return (1);
		i++;
	}
	return (0);
}
