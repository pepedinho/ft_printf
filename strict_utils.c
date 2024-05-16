/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:50:24 by itahri            #+#    #+#             */
/*   Updated: 2024/05/12 13:26:22 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_len	*strict_unsigned_format(va_list args, int ite, int len_format)
{
	unsigned int	nbr;
	t_len			*result;
	int				len;

	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
	nbr = va_arg(args, unsigned int);
	len = dec_len(nbr);
	ft_putnbr_base(nbr, "0123456789");
	result->i = len_format + 1;
	if (ite > len)
		len = ite;
	result->arg_len = len;
	return (result);
}

t_len	*strict_hex_format(va_list args, int ite, int cas, int len_format)
{
	long long int	nbr;
	int				len;
	t_len			*result;

	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
	nbr = va_arg(args, long long int);
	len = hexa_len(nbr);
	if (cas == 1)
		ft_putnbr_base(nbr, "0123456789abcdef");
	else
		ft_putnbr_base(nbr, "0123456789ABCDEF");
	result->i = len_format + 1;
	if (ite > len)
		len = ite;
	result->arg_len = len;
	return (result);
}

static t_len	*check_type_strict(const char c, va_list args, int ite, int len)
{
	if (c == 'c')
		return (strict_car_format(args, ite, len));
	else if (c == 's')
		return (str_strict_format(args, ite, len));
	else if (c == 'd' || c == 'i')
		return (int_strict_format(args, ite, len));
	else if (c == 'p')
		return (mem_strict_format(args, ite, len));
	else if (c == 'u')
		return (strict_unsigned_format(args, ite, len));
	else if (c == 'x')
		return (strict_hex_format(args, ite, 1, len));
	else if (c == 'X')
		return (strict_hex_format(args, ite, 2, len));
	else if (c == '%')
		return (strict_per_format(ite, len));
	return (NULL);
}

t_len	*strict_format(const char *c, va_list args)
{
	t_format	*format;
	t_len		*result;
	int			ite;
	int			len;

	c++;
	format = flags_len_default(c, "csdpuixX");
	if (!format)
		return (NULL);
	ite = ft_atoi(format->str);
	len = ft_strlen(format->str);
	if (!check_sep(*c, "csdpuixX"))
		len += 1;
	result = check_type_strict(format->formater, args, ite, len);
	if (!result)
		return (NULL);
	free_struct(format);
	return (result);
}
