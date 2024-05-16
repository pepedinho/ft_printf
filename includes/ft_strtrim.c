/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-23 22:56:10 by itahri            #+#    #+#             */
/*   Updated: 2024-03-23 22:56:10 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(const char *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	malloc_size(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(s1);
	i = 0;
	while (is_in_set(set, s1[i]))
		i++;
	j = 0;
	while (is_in_set(set, s1[len - j]))
		j++;
	return (len - (i + j) + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*result;

	result = malloc(sizeof(char) * malloc_size(s1, set));
	if (!result)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	k = 0;
	while (is_in_set(set, s1[i]))
		i++;
	while (is_in_set(set, s1[j]))
		j--;
	while (i < j + 1 && s1[i])
	{
		result[k] = s1[i];
		i++;
		k++;
	}
	result[i] = '\0';
	return (result);
}
