/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:21:50 by itahri            #+#    #+#             */
/*   Updated: 2024/05/06 22:39:13 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flags_len(const char *c, char sep)
{
	int		i;
	char	*result;

	// c++;
	i = 0;
	while(c[i] != sep && c[i])
		i++;
	result = malloc(sizeof(char) * i + 1);
	if (!result)
		return (NULL);
	i = 0;
	while(c[i] != sep && c[i])
	{
		result[i] = c[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}