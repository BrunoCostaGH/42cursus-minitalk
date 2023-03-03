/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:01:09 by bsilva-c          #+#    #+#             */
/*   Updated: 2022/11/26 16:56:19 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_string(char *s)
{
	int	len;

	len = 0;
	if (s)
	{
		len = ft_strlen(s);
		write(1, &*s, len);
	}
	else
		len = set_string("(null)") + 1;
	return (--len);
}

int	set_alloc_str(char *s)
{
	int	len;

	len = 0;
	if (s)
		len = set_string(s);
	else
		len = set_string("(null)") + 1;
	free(s);
	return (len);
}

int	set_pointer(void *ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (set_string("(nil)"));
	len += set_string("0x");
	len += set_ulbase((unsigned long)ptr, "0123456789abcdef");
	return (len);
}
