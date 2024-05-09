/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:21:50 by itahri            #+#    #+#             */
/*   Updated: 2024/05/09 17:49:17 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_format	*flags_len(const char *c, char *sep)
{
	int			i;
	char		*str;
	t_format	*result;

	c++;
	i = 0;
	result = malloc(sizeof(t_format));
	if (!result)
		return (NULL);
	while (!check_sep(c[i], sep) && c[i])
		i++;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	result->formater = c[i];
	i = 0;
	while (!check_sep(c[i], sep) && c[i])
	{
		str[i] = c[i];
		i++;
	}
	str[i] = '\0';
	result->str = str;
	return (result);
}

int	support_zero_format(int arg, t_format *format)
{
	int	i;
	int	ite;

	i = 0;
	ite = ft_atoi(format->str);
	if (arg < 0)
		write(1, "-", 1);
	while (i < ite - dec_len_all(arg))
	{
		write(1, "0", 1);
		i++;
	}
	if (arg < 0)
		arg = -arg;
	ft_putnbr(arg);
	free_struct(format);
	return (0);
}

int	zero_format(const char *c, va_list args)
{
	t_format		*format;
	int				decale;
	int				arg;

	format = flags_len(c, "iduxX");
	decale = 2 + ft_strlen(format->str);
	if (format->formater == 'x' || format->formater == 'X')
	{
		arg = va_arg(args, long long int);
		if (format->formater == 'x')
			return (zero_format_hex(arg, 1, format), decale);
		else
			return (zero_format_hex(arg, 2, format), decale);
	}
	else if (format->formater == 'u')
	{
		arg = va_arg(args, unsigned int);
		return (zero_format_unsigned(arg, format), decale);
	}
	else
	{
		arg = va_arg(args, int);
		return (support_zero_format(arg, format) + decale);
	}
}
