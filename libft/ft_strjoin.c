/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:02:03 by bsilva-c          #+#    #+#             */
/*   Updated: 2022/11/10 14:35:58 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (0);
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	return (str);
}
