/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 21:36:21 by itahri            #+#    #+#             */
/*   Updated: 2024/03/24 16:38:29 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*n_src;
	unsigned char	*n_dest;

	n_src = (unsigned char *)src;
	n_dest = (unsigned char *)dest;
	if (n_src < n_dest)
	{
		i = n;
		while (i > 0)
		{
			n_dest[i - 1] = n_src[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			n_dest[i] = n_src[i];
			i++;
		}
	}
	return (dest);
}
