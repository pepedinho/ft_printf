/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:31:44 by itahri            #+#    #+#             */
/*   Updated: 2024/05/11 20:56:11 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_putnbr(int nbr)
{
	char	char_nbr;

	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
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

void	ft_putnbr_base(long long int nbr, char *base)
{
	char	char_nbr;
	int		base_len;

	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
	}
	nbr = (unsigned long long)nbr;
	if (nbr >= base_len)
		ft_putnbr_base(nbr / base_len, base);
	char_nbr = base[nbr % base_len];
	write(1, &char_nbr, 1);
}

void	print_mem(void *ptr)
{
	unsigned long long int	addres_num;

	addres_num = (unsigned long long int)ptr;
	write(1, "0x", 2);
	ft_putnbr_base(addres_num, "0123456789abcdef");
}

t_len	*check_type(const char *c, va_list args)
{
	if (*c == 'c')
		return (car_pr(args));
	else if (*c == 's')
		return (str_pr(args));
	else if (*c == 'd' || *c == 'i')
		return (int_pr(args));
	else if (*c == 'p')
		return (mem_pr(args));
	else if (*c == 'u')
		return (uns_pr(args));
	else if (*c == 'x')
		return (hexl_pr(args, 1));
	else if (*c == 'X')
		return (hexl_pr(args, 2));
	else if (*c == '%')
		return (per_pr());
	return (NULL);
}

t_len	*check_flags(const char *c, va_list args)
{
	c++;
	if (*c == '0')
		return (zero_format(c, args));
	else if (*c == '+')
		return (plus_format(c, args));
	else if (*c == '#')
		return (hasht_format(c, args));
	else if (*c == ' ')
		return (space_format(c, args));
	else if (check_digit(c, "0123456789"))
		return (default_format(c, args));
	else if (*c == '.')
		return (strict_format(c, args));
	else if (*c == '-')
		return (min_format(c, args));
	else
		return (check_type(&c[0], args));
}
