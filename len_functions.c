/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:17:59 by itahri            #+#    #+#             */
/*   Updated: 2024/05/09 17:48:45 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	hexa_len(long long int nbr)
{
	int				len;
	long long int	temp;

	temp = nbr;
	len = 0;
	while (temp != 0)
	{
		temp = temp / 16;
		len++;
	}
	return (len);
}

int	dec_len(unsigned int nbr)
{
	int				len;
	unsigned int	temp;

	temp = nbr;
	len = 0;
	while (temp != 0)
	{
		temp = temp / 10;
		len++;
	}
	return (len);
}

int	dec_len_all(int nbr)
{
	int	len;
	int	temp;

	temp = nbr;
	len = 0;
	if (temp == -2147483648)
		return (11);
	if (temp < 0)
	{
		temp = -temp;
		len++;
	}
	while (temp != 0)
	{
		temp = temp / 10;
		len++;
	}
	return (len);
}
