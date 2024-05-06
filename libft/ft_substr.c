/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-23 20:24:42 by itahri            #+#    #+#             */
/*   Updated: 2024-03-23 20:24:42 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*result;

	result = malloc(len + 1);
	if (!result)
		return (NULL);
	i = start;
	j = 0;
	while (j < len && s[i])
	{
		result[j] = s[i];
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}
