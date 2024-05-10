/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:04:20 by itahri            #+#    #+#             */
/*   Updated: 2024/05/10 14:04:14 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static t_format	*flags_len_min(const char *c, char *sep)
{
	int			i;
	char		*str;
	t_format	*result;

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

static void	check_type_min(const char c, va_list args, int ite)
{
	char	car;

	if (c == 'c')
	{
		car = va_arg(args, int);
		write(1, &car, 1);
	}
	else if (c == 's')
		min_str_format(args, ite);
	else if (c == 'd' || c == 'i')
		min_int_format(args, ite);
	else if (c == 'p')
		min_mem_format(args, ite);
	else if (c == 'u')
		min_unsigned_format(args, ite);
	else if (c == 'x')
		min_hex_format(args, ite, 1);
	else if (c == 'X')
		min_hex_format(args, ite, 2);
	else if (c == '%')
		write(1, "%%", 1);
}

int	min_format(const char *c, va_list args)
{
	t_format	*format;
	int			ite;
	int			len;

	c++;
	format = flags_len_min(c, "sdpuixX");
	ite = ft_atoi(format->str);
	check_type_min(format->formater, args, ite);
	len = ft_strlen(format->str);
	free_struct(format);
	return (len + 2);
}
