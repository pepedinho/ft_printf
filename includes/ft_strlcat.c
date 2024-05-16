/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-22 23:39:07 by itahri            #+#    #+#             */
/*   Updated: 2024-03-22 23:39:07 by itahri           ###   ########fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_min(size_t size, size_t len)
{
	if (size <= len)
		return (size);
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	while (dst[i])
		i++;
	len = i;
	if (size <= ft_strlen(src))
	{
		if (is_min(size, len) == size)
			return (size + ft_strlen(src));
		return (len + ft_strlen(src));
	}
	j = 0;
	while (src[j] && i < size - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (ft_strlen(src) + len);
}
