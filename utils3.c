/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:45:31 by itahri            #+#    #+#             */
/*   Updated: 2024/05/12 13:46:37 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_len	*hasht_format(const char *c, va_list args)
{
	long long int	arg;
	t_len			*result;

	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
	arg = va_arg(args, long long int);
	c++;
	if (*c == 'x')
	{
		write(1, "0x", 2);
		ft_putnbr_base(arg, "0123456789abcdef");
	}
	else if (*c == 'X')
	{
		write(1, "0X", 2);
		ft_putnbr_base(arg, "0123456789ABCDEF");
	}
	result->i = 2;
	result->arg_len = hexa_len(arg);
	return (result);
}

t_len	*space_format(const char *c, va_list args)
{
	t_len	*result;
	int		arg;

	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
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
		result->arg_len = dec_len(arg);
	}
	result->i = 2;
	return (result);
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

void	job(int *i, int *count, t_len *len)
{
	*i += len->i;
	*count += len->arg_len;
	free(len);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
