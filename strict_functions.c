/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:30:32 by itahri            #+#    #+#             */
/*   Updated: 2024/05/12 13:43:50 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_len	*strict_car_format(va_list args, int ite, int format_len)
{
	char	car;
	t_len	*result;
	int		len;

	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
	car = va_arg(args, int);
	len = 1;
	write(1, &car, 1);
	result->i = format_len + 1;
	if (ite > len)
		len = ite;
	result->arg_len = len;
	return (result);
}

t_len	*strict_per_format(int ite, int format_len)
{
	t_len	*result;
	int		len;

	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
	len = 1;
	write(1, "%%", 1);
	result->i = format_len;
	if (ite > len)
		len = ite;
	result->arg_len = len;
	return (result);
}

t_len	*str_strict_format(va_list args, int ite, int len_format)
{
	char	*str;
	t_len	*result;
	char	null_str[7];
	int		len;

	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
	str = va_arg(args, char *);
	if (!str)
	{
		null_cpy(null_str, "(null)");
		str = null_str;
		if (ite < 6)
			len = ft_putstr_strict(str, 0);
		else
			len = ft_putstr_strict(str, ite);
	}
	else
		len = ft_putstr_strict(str, ite);
	result->i = len_format + 1;
	result->arg_len = len;
	return (result);
}

t_len	*int_strict_format(va_list args, int ite, int len_format)
{
	t_len	*result;
	char	*str;
	int		len;
	int		nbr;
	int		i;

	i = 0;
	nbr = va_arg(args, int);
	result = malloc(sizeof(t_len));
	str = ft_itoa(nbr);
	if (!str || !result)
		return (NULL);
	len = ft_strlen(str);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		ite++;
	}
	while (i++ < ite - len)
		write(1, "0", 1);
	result->i = len_format + 1;
	len = max(len, ite);
	result->arg_len = len;
	return (ft_putnbr_spec(nbr), free(str), result);
}

t_len	*mem_strict_format(va_list args, int ite, int len_format)
{
	t_len					*result;
	int						len;
	void					*ptr;
	unsigned long long int	nbr;

	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
	ptr = va_arg(args, void *);
	nbr = (unsigned long long int)ptr;
	if (ptr == (void *)-1)
		len = 16 + 2;
	else if (!ptr)
		len = 3 + 2;
	else
		len = hexa_len(nbr) + 2;
	result->i = len_format + 1;
	result->arg_len = max(len, ite);
	if (ptr == (void *)-1)
		ft_putstr("0xffffffffffffffff");
	else if (!ptr)
		ft_putstr("(nil)");
	else
		print_mem(ptr);
	return (result);
}
