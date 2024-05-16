/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:06:35 by itahri            #+#    #+#             */
/*   Updated: 2024/05/12 12:29:34 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_len	*min_str_format(va_list args, int ite, int format_len)
{
	t_len		*result;
	const char	*str;
	int			len;
	int			i;

	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
	str = va_arg(args, const char *);
	i = 0;
	len = ft_strlen(str);
	ft_putstr(str);
	while (i < ite - len)
	{
		write(1, " ", 1);
		i++;
	}
	result->i = format_len;
	if (ite > len)
		len = ite;
	result->arg_len = len;
	return (result);
}

t_len	*min_int_format(va_list args, int ite, int format_len)
{
	char	*str;
	int		i;
	int		len;
	int		nbr;
	t_len	*result;

	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
	i = 0;
	nbr = va_arg(args, int);
	str = ft_itoa(nbr);
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	ft_putnbr(nbr);
	while (i++ < (ite + 1) - len)
		write(1, " ", 1);
	free(str);
	result->i = format_len;
	if (ite > len)
		len = ite;
	result->arg_len = len;
	return (result);
}

t_len	*min_mem_format(va_list args, int ite, int format_len)
{
	int						i;
	int						len;
	void					*ptr;
	unsigned long long int	nbr;
	t_len					*result;

	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
	i = 0;
	ptr = va_arg(args, void *);
	nbr = (unsigned long long int)ptr;
	len = hexa_len(nbr);
	print_mem(ptr);
	while (i++ < (ite + 1) - (len + 2))
		write(1, " ", 1);
	result->i = format_len;
	if (ite > len + 2)
		len = ite;
	else
		len += 2;
	result->arg_len = len;
	return (result);
}

t_len	*min_unsigned_format(va_list args, int ite, int format_len)
{
	unsigned int	nbr;
	int				i;
	int				len;
	char			*str;
	t_len			*result;

	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
	i = 0;
	nbr = va_arg(args, unsigned int);
	str = ft_itoa(nbr);
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	ft_putnbr_base(nbr, "0123456789");
	while (i++ < (ite + 1) - len)
		write(1, " ", 1);
	free(str);
	result->i = format_len;
	if (ite > len)
		len = ite;
	result->arg_len = len;
	return (result);
}

t_len	*min_hex_format(va_list args, int ite, int cas, int format_len)
{
	long long int	nbr;
	int				i;
	int				len;
	t_len			*result;

	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
	i = 0;
	nbr = va_arg(args, long long int);
	len = hexa_len(nbr);
	if (cas == 1)
		ft_putnbr_base(nbr, "0123456789abcdef");
	else
		ft_putnbr_base(nbr, "0123456789ABCDEF");
	while (i < ite - len)
	{
		write(1, " ", 1);
		i++;
	}
	result->i = format_len;
	if (ite > len)
		len = ite;
	result->arg_len = len;
	return (result);
}
