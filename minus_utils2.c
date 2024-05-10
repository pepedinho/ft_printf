/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:06:35 by itahri            #+#    #+#             */
/*   Updated: 2024/05/10 14:05:35 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	min_str_format(va_list args, int ite)
{
	const char	*str;
	int			i;
	int			len;

	str = va_arg(args, const char *);
	i = 0;
	len = ft_strlen(str);
	ft_putstr(str);
	while (i < ite - len)
	{
		write(1, " ", 1);
		i++;
	}
}

void	min_int_format(va_list args, int ite)
{
	char	*str;
	int		i;
	int		len;
	int		nbr;

	i = 0;
	nbr = va_arg(args, int);
	str = ft_itoa(nbr);
	if (!str)
		return ;
	len = ft_strlen(str);
	ft_putnbr(nbr);
	while (i < ite - len)
	{
		write(1, " ", 1);
		i++;
	}
	free(str);
}

void	min_mem_format(va_list args, int ite)
{
	int						i;
	int						len;
	void					*ptr;
	unsigned long long int	nbr;

	i = 0;
	ptr = va_arg(args, void *);
	nbr = (unsigned long long int)ptr;
	len = hexa_len(nbr);
	print_mem(ptr);
	while (i < ite - (len + 2))
	{
		write(1, " ", 1);
		i++;
	}
}

void	min_unsigned_format(va_list args, int ite)
{
	unsigned int	nbr;
	int				i;
	int				len;
	char			*str;

	i = 0;
	nbr = va_arg(args, unsigned int);
	str = ft_itoa(nbr);
	if (!str)
		return ;
	len = ft_strlen(str);
	ft_putnbr_base(nbr, "0123456789");
	while (i < ite - len)
	{
		write(1, " ", 1);
	}
	free(str);
}

void	min_hex_format(va_list args, int ite, int cas)
{
	long long int	nbr;
	int				i;
	int				len;

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
}
