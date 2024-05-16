/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:01:59 by itahri            #+#    #+#             */
/*   Updated: 2024/05/12 11:26:33 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_format	*flags_len_default(const char *c, char *sep)
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
	if (i == 0)
		str[0] = '0';
	result->str = str;
	return (result);
}

static t_len	*check_type_def(const char c, va_list args, int ite, int len)
{
	if (c == 'c')
		return (car_format(args, ite, len));
	else if (c == 's')
		return (str_format(args, ite, len));
	else if (c == 'd' || c == 'i')
		return (int_format(args, ite, len));
	else if (c == 'p')
		return (mem_format(args, ite, len));
	else if (c == 'u')
		return (unsigned_format(args, ite, len));
	else if (c == 'x')
		return (hex_format(args, ite, 1, len));
	else if (c == 'X')
		return (hex_format(args, ite, 2, len));
	else if (c == '%')
		return (per_format(ite, len));
	return (NULL);
}

t_len	*default_format(const char *c, va_list args)
{
	t_format	*format;
	t_len		*result;
	int			ite;
	int			len;

	format = flags_len_default(c, "csdpuixX");
	if (!format)
		return (NULL);
	ite = ft_atoi(format->str);
	len = ft_strlen(format->str);
	result = check_type_def(format->formater, args, ite, len);
	if (!result)
		return (NULL);
	free_struct(format);
	return (result);
}
