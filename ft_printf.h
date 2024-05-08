/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:45:22 by itahri            #+#    #+#             */
/*   Updated: 2024/05/08 17:04:00 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_format
{
	char	*str;
	char	formater;
}			t_format;

t_format	*flags_len(const char *c, char *sep);

int			check_flags(const char *c, va_list args);
int			check_sep(char c, char *sep);
void		ft_putnbr(int nbr);
void		print_mem(void *ptr);
void		check_type(const char *c, va_list args);
void		ft_putnbr_base(long long int nbr, char *base);

int			zero_format_unsigned(unsigned int arg, char *it_nbr);
int			zero_format_hex(long long int arg, int cas, char *it_nbr);
int			zero_format(const char *c, va_list args);
int			plus_format(const char *c, va_list args);
void		free_struct(t_format *format);

int			hexa_len(long long int nbr);
int			dec_len(unsigned int nbr);
int			dec_len_all(int nbr);

void		ft_putstr(const char *str);

#endif