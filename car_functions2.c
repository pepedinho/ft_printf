/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   car_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 11:24:02 by itahri            #+#    #+#             */
/*   Updated: 2024/05/12 12:38:22 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_len	*min_per_format(int ite, int format_len)
{
	t_len	*result;
	int		i;
	int		len;

	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
	i = 0;
	len = 1;
	write(1, "%%", 1);
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

t_len	*mem_pr_case(t_len *result, int cas, int decal)
{
	if (cas == 1)
	{
		result->i = decal;
		result->arg_len = 18;
		ft_putstr("0xffffffffffffffff");
		return (result);
	}
	else
	{
		result->i = decal;
		result->arg_len = 5;
		ft_putstr("(nil)");
		return (result);
	}
}
