/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:21:17 by bsilva-c          #+#    #+#             */
/*   Updated: 2022/11/28 13:22:16 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_numbers(unsigned int n)
{
	unsigned int	temp;
	unsigned int	length;

	length = 0;
	temp = 1;
	if (n == 0)
		return (1);
	while (temp <= n && length < 10)
	{
		length++;
		temp *= 10;
	}
	return (length);
}

char	*ft_utoa(unsigned int n)
{
	char	*s;
	int		i;

	i = count_numbers(n);
	s = ft_calloc(i + 1, sizeof(char));
	if (!s)
		return (0);
	else if (n == 0)
		s[0] = '0';
	while (n > 0)
	{
		s[i-- - 1] = n % 10 + '0';
		n /= 10;
	}
	return (s);
}
