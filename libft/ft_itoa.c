/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:27:41 by bsilva-c          #+#    #+#             */
/*   Updated: 2022/11/07 16:08:25 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_numbers(int n)
{
	int	length;
	int	temp;

	length = 0;
	temp = 1;
	if (n == 0)
		return (1);
	if (n <= -1000000000)
		return (11);
	if (n < 0)
	{
		length = 1;
		n *= -1;
	}
	while (temp <= n && length < 10)
	{
		length++;
		temp *= 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i;

	i = count_numbers(n);
	s = ft_calloc(i + 1, sizeof(char));
	if (!s)
		return (0);
	if (n == -2147483648)
	{
		s[1] = '2';
		n = -147483648;
	}
	else if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		s[i-- - 1] = n % 10 + '0';
		n /= 10;
	}
	return (s);
}
