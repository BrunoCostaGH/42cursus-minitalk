/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:11:32 by bsilva-c          #+#    #+#             */
/*   Updated: 2022/11/14 18:19:42 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//return numbers of split strings
static int	string_count(char const *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (*str)
	{
		if (*str++ == c)
			i++;
	}
	return (++i);
}

//return numbers of current string characters
static int	char_count(char const *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (*str != c && *str)
	{
		str++;
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		k;

	i = -1;
	k = 0;
	result = ft_calloc(string_count(s, c) + 1, sizeof(char *));
	if (!result)
		return (0);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			result[++i] = ft_calloc(char_count(s, c) + 1, sizeof(char));
			if (!result[i])
				return (0);
			while (*s != c && *s)
				result[i][k++] = *s++;
			k = 0;
		}
	}
	return (result);
}
