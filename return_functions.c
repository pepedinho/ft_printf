/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:58:47 by itahri            #+#    #+#             */
/*   Updated: 2024/05/12 12:39:13 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_len	*str_pr(va_list args)
{
	int			decal;
	const char	*str;
	t_len		*result;

	decal = 1;
	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
	str = va_arg(args, const char *);
	if (!str)
	{
		result->arg_len = 6;
		ft_putstr("(null)");
		result->i = decal;
		return (result);
	}
	ft_putstr(str);
	result->i = decal;
	result->arg_len = ft_strlen(str);
	return (result);
}

t_len	*int_pr(va_list args)
{
	int		decal;
	int		arg;
	char	*str;
	t_len	*result;

	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
	arg = va_arg(args, int);
	str = ft_itoa(arg);
	if (!str)
		return (NULL);
	ft_putnbr(arg);
	decal = 1;
	result->i = decal;
	result->arg_len = ft_strlen(str);
	free(str);
	return (result);
}

t_len	*mem_pr(va_list args)
{
	unsigned long long int	temp;
	int						decal;
	void					*arg;
	t_len					*result;

	decal = 1;
	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
	arg = va_arg(args, void *);
	if (arg == (void *)-1)
		return (mem_pr_case(result, 1, decal));
	if (!arg)
		return (mem_pr_case(result, 2, decal));
	print_mem(arg);
	temp = (unsigned long long int)arg;
	result->i = decal;
	result->arg_len = hexa_len(temp) + 2;
	return (result);
}

t_len	*uns_pr(va_list args)
{
	int						decal;
	unsigned int			arg;
	t_len					*result;

	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
	arg = va_arg(args, unsigned int);
	ft_putnbr_base(arg, "0123456789");
	decal = 1;
	result->i = decal;
	result->arg_len = dec_len(arg);
	return (result);
}

t_len	*hexl_pr(va_list args, int cas)
{
	int						decal;
	long long int			arg;
	t_len					*result;

	result = malloc(sizeof(t_len));
	if (!result)
		return (NULL);
	arg = va_arg(args, long long int);
	if (cas == 1)
		ft_putnbr_base(arg, "0123456789abcdef");
	else
		ft_putnbr_base(arg, "0123456789ABCDEF");
	decal = 1;
	result->i = decal;
	result->arg_len = hexa_len(arg);
	return (result);
}
