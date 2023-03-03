/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:19:15 by bsilva-c          #+#    #+#             */
/*   Updated: 2022/11/28 13:19:17 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	validate_base(char *base, int lenght)
{
	int	i;
	int	j;

	i = 0;
	if (base[i] == '\0' || lenght == 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] <= 32 || base[i] == 127)
			return (0);
		j = i + 1;
		while (j < lenght)
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	set_ubase(unsigned int nbr, char *base)
{
	unsigned int	base_len;
	unsigned int	nbr_len;

	base_len = 0;
	nbr_len = 0;
	while (base[base_len])
		base_len++;
	if (validate_base(base, base_len))
	{
		if (nbr < base_len)
		{
			ft_putchar_fd(base[nbr], 1);
			nbr_len++;
		}
		if (nbr >= base_len)
		{
			nbr_len += set_ubase((nbr / base_len), base);
			nbr_len += set_ubase((nbr % base_len), base);
		}
	}
	return (nbr_len);
}

int	set_ulbase(unsigned long nbr, char *base)
{
	unsigned long int	base_len;
	unsigned int		nbr_len;

	base_len = 0;
	nbr_len = 0;
	while (base[base_len])
		base_len++;
	if (validate_base(base, base_len))
	{
		if (nbr < base_len)
		{
			ft_putchar_fd(base[nbr], 1);
			nbr_len++;
		}
		if (nbr >= base_len)
		{
			nbr_len += set_ulbase((nbr / base_len), base);
			nbr_len += set_ulbase((nbr % base_len), base);
		}
	}
	return (nbr_len);
}
