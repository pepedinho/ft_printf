/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:45:22 by itahri            #+#    #+#             */
/*   Updated: 2024/05/12 13:44:35 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_format
{
	char	*str;
	char	formater;
}			t_format;

typedef struct s_len
{
	int	i;
	int	arg_len;
}		t_len;
int			ft_printf(const char *format, ...);
void		job(int *i, int *count, t_len *len);

t_format	*flags_len(const char *c, char *sep);
t_format	*flags_len_default(const char *c, char *sep);

t_len		*check_flags(const char *c, va_list args);
int			check_sep(char c, char *sep);
void		ft_putnbr(int nbr);
void		print_mem(void *ptr);
void		ft_putnbr_base(long long int nbr, char *base);

t_len		*zero_format_uns(unsigned int arg, t_format *format, int decale);
t_len		*zero_hex(long long int arg, int cas, t_format *format, int decale);
t_len		*zero_format(const char *c, va_list args);
t_len		*plus_format(const char *c, va_list args);
t_len		*hasht_format(const char *c, va_list args);
t_len		*space_format(const char *c, va_list args);

void		free_struct(t_format *format);

int			hexa_len(long long int nbr);
int			dec_len(unsigned int nbr);
int			dec_len_all(int nbr);
int			check_digit(const char *c, char *digit);
int			max(int a, int b);

void		ft_putstr(const char *str);
int			ft_putstr_strict(const char *str, int stop);
int			subdivide_dec(int nbr, int ite);
void		null_cpy(char *str, char *cop_str);
void		ft_putnbr_spec(int nbr);

t_len		*strict_format(const char *c, va_list args);

t_len		*strict_per_format(int ite, int format_len);
t_len		*strict_car_format(va_list args, int ite, int format_len);
t_len		*int_strict_format(va_list args, int ite, int len_format);
t_len		*str_strict_format(va_list args, int ite, int len_format);
t_len		*mem_strict_format(va_list args, int ite, int len_format);
t_len		*strict_unsigned_format(va_list args, int ite, int len_format);
t_len		*strict_hex_format(va_list args, int ite, int cas, int len_format);

t_len		*check_type(const char *c, va_list args);

t_len		*str_pr(va_list args);
t_len		*int_pr(va_list args);
t_len		*mem_pr(va_list args);
t_len		*uns_pr(va_list args);
t_len		*hexl_pr(va_list args, int cas);
t_len		*car_pr(va_list args);
t_len		*per_pr(void);
t_len		*mem_pr_case(t_len *result, int cas, int decal);

t_len		*default_format(const char *c, va_list args);

t_len		*str_format(va_list args, int ite, int format_len);
t_len		*int_format(va_list args, int ite, int format_len);
t_len		*mem_format(va_list args, int ite, int format_len);
t_len		*unsigned_format(va_list args, int ite, int format_len);
t_len		*hex_format(va_list args, int ite, int cas, int format_len);
t_len		*car_format(va_list args, int ite, int format_len);
t_len		*per_format(int ite, int format_len);

t_len		*str_format2(int len, t_len *result, int len_format);
t_len		*int_format2(int len, t_len *result, int nbr, int len_format);
t_len		*mem_format2(int len, t_len *result, void *ptr, int len_format);

t_len		*min_format(const char *c, va_list args);

t_len		*min_str_format(va_list args, int ite, int format_len);
t_len		*min_int_format(va_list args, int ite, int format_len);
t_len		*min_mem_format(va_list args, int ite, int format_len);
t_len		*min_unsigned_format(va_list args, int ite, int format_len);
t_len		*min_hex_format(va_list args, int ite, int cas, int format_len);
t_len		*min_car_format(va_list args, int ite, int format_len);
t_len		*min_per_format(int ite, int format_len);

#endif