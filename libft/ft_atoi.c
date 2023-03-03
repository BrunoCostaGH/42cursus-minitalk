/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:48:52 by bsilva-c          #+#    #+#             */
/*   Updated: 2022/11/04 17:48:55 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	n;
	int	signal;

	i = 0;
	n = 0;
	signal = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
		signal *= -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = nptr[i] - 48 + (n * 10);
		i++;
	}
	return (n * signal);
}
