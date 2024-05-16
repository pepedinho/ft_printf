/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_func2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:34:31 by itahri            #+#    #+#             */
/*   Updated: 2024/05/12 12:22:51 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_putstr_strict(const char *str, int stop)
{
	int	i;

	i = 0;
	while (str[i] && i < stop)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	subdivide_dec(int nbr, int ite)
{
	int	i;
	int	temp;

	i = 0;
	temp = nbr;
	while (i < ite)
	{
		temp = temp / 10;
		i++;
	}
	return (temp);
}

void	null_cpy(char *str, char *cop_str)
{
	int	i;

	i = 0;
	while (cop_str[i])
	{
		str[i] = cop_str[i];
		i++;
	}
}

void	ft_putnbr_spec(int nbr)
{
	char	char_nbr;

	if (nbr == -2147483648)
	{
		write(1, "2147483648", 10);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	char_nbr = (nbr % 10) + '0';
	write(1, &char_nbr, 1);
}
