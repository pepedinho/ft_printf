/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 11:35:15 by itahri            #+#    #+#             */
/*   Updated: 2024/05/12 12:03:12 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_len	*str_format2(int len, t_len *result, int len_format)
{
	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
	result->i = len_format + 1;
	result->arg_len = len;
	return (result);
}

t_len	*int_format2(int len, t_len *result, int nbr, int len_format)
{
	result->i = len_format + 1;
	result->arg_len = len;
	ft_putnbr(nbr);
	return (result);
}

t_len	*mem_format2(int len, t_len *result, void *ptr, int len_format)
{
	result->i = len_format + 1;
	result->arg_len = len;
	if (ptr == (void *)-1)
		ft_putstr("0xffffffffffffffff");
	else if (!ptr)
		ft_putstr("(nil)");
	else
		print_mem(ptr);
	return (result);
}
