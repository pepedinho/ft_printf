/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:31:29 by itahri            #+#    #+#             */
/*   Updated: 2024/05/08 17:02:47 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	zero_format_hex(long long int arg, int cas, char *it_nbr)
{
	int	i;
	int	ite;

	i = 0;
	ite = ft_atoi(it_nbr);
	while (i < ite - hexa_len(arg))
	{
		write(1, "0", 1);
		i++;
	}
	if (cas == 1)
		ft_putnbr_base(arg, "0123456789abcdef");
	else
		ft_putnbr_base(arg, "0123456789ABCDEF");
	return (1);
}

int	check_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	plus_format(const char *c, va_list args)
{
	int	decal;
	int	arg;

	c++;
	decal = 1;
	if (c[0] == 'd' || c[0] == 'i')
	{
		arg = va_arg(args, int);
		if (arg >= 0)
			write(1, "+", 1);
		decal++;
		ft_putnbr(arg);
	}
	return (decal);
}

void	free_struct(t_format *format)
{
	free(format->str);
	free(format);
}

int	zero_format_unsigned(unsigned int arg, char *it_nbr)
{
	int	i;
	int	ite;

	ite = ft_atoi(it_nbr);
	i = 0;
	while (i < ite - dec_len(arg))
	{
		write(1, "0", 1);
		i++;
	}
	ft_putnbr_base(arg, "0123456789");
	return (1);
}
