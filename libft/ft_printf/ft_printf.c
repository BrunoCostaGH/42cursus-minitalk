/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:58:26 by bsilva-c          #+#    #+#             */
/*   Updated: 2022/11/26 16:57:39 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	set_data(va_list arg_list, char c)
{
	int		len;

	len = 1;
	if (c == 'c')
		ft_putchar_fd(va_arg(arg_list, int), 1);
	else if (c == 's')
		len += set_string(va_arg(arg_list, char *));
	else if (c == 'p')
		len += set_pointer(va_arg(arg_list, void *));
	else if (c == 'd')
		len += set_alloc_str(ft_itoa(va_arg(arg_list, int)));
	else if (c == 'i')
		len += set_alloc_str(ft_itoa(va_arg(arg_list, int)));
	else if (c == 'u')
		len += set_alloc_str(ft_utoa(va_arg(arg_list, unsigned int)));
	else if (c == 'x')
		len += set_ubase(va_arg(arg_list, int), "0123456789abcdef") - 1;
	else if (c == 'X')
		len += set_ubase(va_arg(arg_list, int), "0123456789ABCDEF") - 1;
	else if (c == '%')
		ft_putchar_fd(c, 1);
	return (--len);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg_list;
	int		i;
	int		len;

	va_start(arg_list, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%' && ft_strchr("cspdiuxX%", s[i + 1]))
			len += set_data(arg_list, s[++i]);
		else
			ft_putchar_fd(s[i], 1);
		i++;
		len++;
	}
	va_end(arg_list);
	return (len);
}
