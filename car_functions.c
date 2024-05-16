/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   car_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:21:36 by itahri            #+#    #+#             */
/*   Updated: 2024/05/12 11:25:40 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_len	*car_pr(va_list args)
{
	char	car;
	t_len	*result;

	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
	car = va_arg(args, int);
	write(1, &car, 1);
	result->arg_len = 1;
	result->i = 1;
	return (result);
}

t_len	*per_pr(void)
{
	t_len	*result;

	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
	write(1, "%%", 1);
	result->arg_len = 1;
	result->i = 1;
	return (result);
}

t_len	*car_format(va_list args, int ite, int format_len)
{
	char	car;
	t_len	*result;
	int		i;
	int		len;

	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
	car = va_arg(args, int);
	i = 0;
	len = 1;
	while (i < ite - len)
	{
		write(1, " ", 1);
		i++;
	}
	write(1, &car, 1);
	result->i = format_len + 1;
	if (ite > len)
		len = ite;
	result->arg_len = len;
	return (result);
}

t_len	*per_format(int ite, int format_len)
{
	t_len	*result;
	int		i;
	int		len;

	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
	i = 0;
	len = 1;
	while (i < ite - len)
	{
		write(1, " ", 1);
		i++;
	}
	write(1, "%%", 1);
	result->i = format_len;
	if (ite > len)
		len = ite;
	result->arg_len = len;
	return (result);
}

t_len	*min_car_format(va_list args, int ite, int format_len)
{
	char	car;
	t_len	*result;
	int		i;
	int		len;

	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
	car = va_arg(args, int);
	i = 0;
	len = 1;
	write(1, &car, 1);
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
