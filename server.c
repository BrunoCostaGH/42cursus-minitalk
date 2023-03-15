/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <bsilva-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:32:01 by bsilva-c          #+#    #+#             */
/*   Updated: 2023/03/15 19:20:12 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*void	print_bits(char ch)
{
	int i;

	for (i = 0; i < 8; i++) {
		ft_printf("%d", !!((ch << i) & 0x80));
	}
	ft_printf("\n");
}*/

void	handler(int sig)
{
	static char	ch;
	static int	bits;

	if (!ch)
		ch = 0;
	if (!bits)
		bits = 0;
	if (sig == SIGUSR1)
		ch |= 1 << (7 - bits);
	else if (sig == SIGUSR2)
		ch &= ~(1 << (7 - bits));
	bits++;
	if (bits == 8)
	{
		write(1, &ch, 1);
		ch = 0;
		bits = 0;
	}
}

void	set_handler(void)
{
	struct sigaction	sa;

	sa.sa_handler = &handler;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(void)
{
	int	serverpid;

	serverpid = getpid();
	ft_printf("Server PID: %d\n", serverpid);
	set_handler();
	while (1)
		pause();
	return (0);
}
