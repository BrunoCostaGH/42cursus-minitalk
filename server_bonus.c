/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <bsilva-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:06:09 by bsilva-c          #+#    #+#             */
/*   Updated: 2023/09/04 13:31:39 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	clear_static_var(char *ch, int *bits, int *pid)
{
	*ch = 0;
	*bits = 0;
	*pid = 0;
}

static void	action(int sig, siginfo_t *info, void *context)
{
	static char	ch;
	static int	bits;
	static int	pid;

	if (pid && pid != info->si_pid)
		clear_static_var(&ch, &bits, &pid);
	pid = info->si_pid;
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
		clear_static_var(&ch, &bits, &pid);
	}
	kill(info->si_pid, sig);
}

static void	set_sigaction(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &action;
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
	set_sigaction();
	while (1)
		pause();
	return (0);
}
