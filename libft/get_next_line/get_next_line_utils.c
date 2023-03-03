/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:55:26 by bsilva-c          #+#    #+#             */
/*   Updated: 2022/12/14 11:24:17 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_to_stash(char *s1, char const *s2, int len)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_calloc(get_len(s1) + get_len(s2) + 1, sizeof(char));
	if (!str)
		return (0);
	if (s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		free(s1);
		s1 = 0;
	}
	while (*s2 && len--)
		str[i++] = *s2++;
	return (str);
}

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

char	*get_line(char const *s, char c)
{
	char	*result;
	int		i;

	i = 0;
	result = ft_calloc(char_count(s, c) + 2, sizeof(char));
	if (!result)
		return (0);
	while ((*s) != c && *s)
		result[i++] = *s++;
	if (*s)
		result[i] = c;
	return (result);
}
