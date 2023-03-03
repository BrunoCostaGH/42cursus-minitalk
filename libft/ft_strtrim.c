/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:40:28 by bsilva-c          #+#    #+#             */
/*   Updated: 2022/11/12 18:19:20 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//returns pointer to start of trimmed string
static char	*check_start(const char *s1, const char *set)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s1;
	while (str[i])
	{
		if (ft_strchr(set, str[i]) == 0)
			break ;
		i++;
	}
	return (str + i);
}

//returns size of trimmed string
static int	check_end(const char *s1, const char *set)
{
	char	*str;
	int		i;

	i = ft_strlen(s1) - 1;
	str = (char *)s1;
	while (str[i] && i >= 0)
	{
		if (ft_strchr(set, str[i]) == 0)
			break ;
		i--;
	}
	return (++i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*result;
	int		i;
	int		strlen;

	i = 0;
	if (!s1 || !set)
		return (0);
	str = check_start(s1, set);
	strlen = check_end(str, set);
	result = ft_calloc(strlen + 1, sizeof(char));
	if (!result)
		return (0);
	while (i < strlen)
	{
		result[i] = *str;
		i++;
		str++;
	}
	return (result);
}
