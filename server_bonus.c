/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <bsilva-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:06:09 by bsilva-c          #+#    #+#             */
/*   Updated: 2023/04/14 13:17:07 by bsilva-c         ###   ########.fr       */
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

void	sa_sig(int sig, siginfo_t *info, void *context)
{
	static char	ch;
	static int	bits;

	(void)context;
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
	kill(info->si_pid, sig);
}

void	set_sig(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &sa_sig;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(void)
{
	int	serverpid;

	serverpid = getpid();
	ft_printf("Server PID: %d\n", serverpid);
	set_sig();
	while (1)
		pause();
	return (0);
}
