/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:07:35 by itahri            #+#    #+#             */
/*   Updated: 2024/05/09 17:48:33 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void str_format(va_list args, int ite)
{
	const char	*str;
	int		i;
	int		len;

	str = va_arg(args, const char *);
	i = 0;
	len = ft_strlen(str);
	while (i < ite - len)
	{
		write(1, " ", 1);
		i++;
	}
	ft_putstr(str);
}

void	int_format(va_list args, int ite)
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
	while(i < ite - len)
	{
		write(1, " ", 1);
		i++;
	}
	ft_putnbr(nbr);
	free(str);
}

void	mem_format(va_list args, int ite)
{
	int 					i;
	int						len;
	void					*ptr;
	unsigned long long int	nbr;

	i = 0;
	ptr = va_arg(args, void *);
	nbr = (unsigned long long int)ptr;
	len = hexa_len(nbr);
	while (i < ite - (len + 2))
	{
		write(1, " ", 1);
		i++;
	}
	print_mem(ptr);
}

void	unsigned_format(va_list args, int ite)
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
	while (i < ite - len)
	{
		write(1, " ", 1);
	}
	ft_putnbr_base(nbr, "0123456789");
	free(str);
}

void	hex_format(va_list args, int ite, int cas)
{
	long long int	nbr;
	int				i;
	int				len;

	i = 0;
	nbr = va_arg(args, long long int);
	len = hexa_len(nbr);
	while (i < ite - len)
	{
		write(1, " ", 1);
		i++;
	}
	if (cas == 1)
		ft_putnbr_base(nbr, "0123456789abcdef");
	else
		ft_putnbr_base(nbr, "0123456789ABCDEF");
}