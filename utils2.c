/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:31:29 by itahri            #+#    #+#             */
/*   Updated: 2024/05/12 13:35:11 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_len	*zero_hex(long long int arg, int cas, t_format *format, int decale)
{
	int		i;
	int		ite;
	t_len	*result;

	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
	i = 0;
	ite = ft_atoi(format->str);
	while (i < ite - hexa_len(arg))
	{
		write(1, "0", 1);
		i++;
	}
	if (cas == 1)
		ft_putnbr_base(arg, "0123456789abcdef");
	else
		ft_putnbr_base(arg, "0123456789ABCDEF");
	free_struct(format);
	result->i = decale;
	result->arg_len = hexa_len(arg);
	return (result);
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

t_len	*plus_format(const char *c, va_list args)
{
	int		decal;
	int		arg;
	t_len	*result;

	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
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
	result->i = decal;
	result->arg_len = dec_len(arg);
	return (result);
}

void	free_struct(t_format *format)
{
	free(format->str);
	free(format);
}

t_len	*zero_format_uns(unsigned int arg, t_format *format, int decale)
{
	int		i;
	int		ite;
	int		len;
	t_len	*result;

	result = malloc(sizeof(t_len));
	ite = ft_atoi(format->str);
	i = 0;
	len = dec_len(arg);
	while (i < ite - len)
	{
		write(1, "0", 1);
		i++;
	}
	ft_putnbr_base(arg, "0123456789");
	if (ite > len)
		len = ite;
	result->arg_len = ite;
	result->i = decale;
	free_struct(format);
	return (result);
}
