/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:27:09 by bsilva-c          #+#    #+#             */
/*   Updated: 2022/11/10 15:08:35 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*str;
	char	*result;

	i = 0;
	str = (char *)s;
	if (!str)
		return (0);
	result = ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (0);
	while (*str)
	{
		if (!start--)
		{
			while (len)
			{
				result[i++] = *str++;
				len--;
			}
			break ;
		}
		str++;
	}
	return (result);
}
