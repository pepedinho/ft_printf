/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-23 02:14:33 by itahri            #+#    #+#             */
/*   Updated: 2024-03-23 02:14:33 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		buff;
	char	*ptr;

	i = 0;
	buff = i;
	ptr = NULL;
	while (s[i])
	{
		if (s[i] == c)
			buff = i;
		i++;
	}
	if (buff)
	{
		ptr = (char *)&s[buff];
		return (ptr);
	}
	return (NULL);
}
