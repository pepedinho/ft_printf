/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:04:20 by itahri            #+#    #+#             */
/*   Updated: 2024/05/11 15:50:24 by itahri           ###   ########.fr       */
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

static t_len	*check_type_min(const char c, va_list args, int ite, int len)
{
	if (c == 'c')
		return (min_car_format(args, ite, len));
	else if (c == 's')
		return (min_str_format(args, ite, len));
	else if (c == 'd' || c == 'i')
		return (min_int_format(args, ite, len));
	else if (c == 'p')
		return (min_mem_format(args, ite, len));
	else if (c == 'u')
		return (min_unsigned_format(args, ite, len));
	else if (c == 'x')
		return (min_hex_format(args, ite, 1, len));
	else if (c == 'X')
		return (min_hex_format(args, ite, 2, len));
	else if (c == '%')
		return (min_per_format(ite, len));
	return (NULL);
}

t_len	*min_format(const char *c, va_list args)
{
	t_format	*format;
	t_len		*result;
	int			ite;
	int			len;

	c++;
	format = flags_len_min(c, "sdpuixX");
	if (!format)
		return (NULL);
	ite = ft_atoi(format->str);
	len = ft_strlen(format->str);
	result = check_type_min(format->formater, args, ite, len + 2);
	if (!result)
		return (NULL);
	free_struct(format);
	return (result);
}
