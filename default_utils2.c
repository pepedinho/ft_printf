/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:07:35 by itahri            #+#    #+#             */
/*   Updated: 2024/05/12 12:02:38 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_len	*str_format(va_list args, int ite, int len_format)
{
	const char	*str;
	t_len		*result;
	int			i;
	int			len;
	int			cas;

	i = 0;
	result = NULL;
	str = va_arg(args, const char *);
	if (!str)
	{
		len = 6;
		cas = 2;
	}
	else
		len = ft_strlen(str);
	while (i++ < ite - len)
		write(1, " ", 1);
	if (cas == 2)
		ft_putstr("(null)");
	else
		ft_putstr(str);
	if (ite > len)
		len = ite;
	return (str_format2(len, result, len_format));
}

t_len	*int_format(va_list args, int ite, int len_format)
{
	t_len	*result;
	char	*str;
	int		i;
	int		len;
	int		nbr;

	i = 0;
	nbr = va_arg(args, int);
	str = ft_itoa(nbr);
	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	while (i < ite - len)
	{
		write(1, " ", 1);
		i++;
	}
	if (ite > len)
		len = ite;
	return (free(str), int_format2(len, result, nbr, len_format));
}

t_len	*mem_format(va_list args, int ite, int len_format)
{
	t_len					*result;
	int						i;
	int						len;
	void					*ptr;
	unsigned long long int	nbr;

	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
	i = 0;
	ptr = va_arg(args, void *);
	nbr = (unsigned long long int)ptr;
	if (ptr == (void *)-1)
		len = 16;
	else if (!ptr)
		len = 3;
	else
		len = hexa_len(nbr);
	while (i++ < ite - (len + 2))
		write(1, " ", 1);
	if (ite > len + 2)
		len = ite;
	else
		len += 2;
	return (mem_format2(len, result, ptr, len_format));
}

t_len	*unsigned_format(va_list args, int ite, int len_format)
{
	unsigned int	nbr;
	t_len			*result;
	int				i;
	int				len;

	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
	i = 0;
	nbr = va_arg(args, unsigned int);
	len = dec_len(nbr);
	while (i < ite - len)
	{
		write(1, " ", 1);
		i++;
	}
	ft_putnbr_base(nbr, "0123456789");
	result->i = len_format + 1;
	if (ite > len)
		len = ite;
	result->arg_len = len;
	return (result);
}

t_len	*hex_format(va_list args, int ite, int cas, int len_format)
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
	while (i < ite - len)
	{
		write(1, " ", 1);
		i++;
	}
	if (cas == 1)
		ft_putnbr_base(nbr, "0123456789abcdef");
	else
		ft_putnbr_base(nbr, "0123456789ABCDEF");
	result->i = len_format + 1;
	if (ite > len)
		len = ite;
	result->arg_len = len;
	return (result);
}
