/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:06:02 by bsilva-c          #+#    #+#             */
/*   Updated: 2022/12/29 14:39:52 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(pid_t serverpid, char *message)
{
	int		bits;
	char	ch;

	while (*message)
	{
		ch = *message;
		bits = 8 * sizeof(ch);
		while (bits--)
		{
			if (ch >> bits & 1)
				kill(serverpid, SIGUSR1);
			else
				kill(serverpid, SIGUSR2);
			usleep(100);
		}
		message++;
	}
}

void	handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("%s", "Received signal SIGUSR1\n");
	else if (signum == SIGUSR2)
		ft_printf("%s", "Received signal SIGUSR2\n");
}

void	set_handler(void)
{
	struct sigaction	sa;

	sa.sa_handler = &handler;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(int argc, char **argv)
{
	pid_t	serverpid;

	if (argc == 3)
	{
		serverpid = ft_atoi(argv[1]);
		if (kill(serverpid, 0))
		{
			ft_printf("%s", "Server is not started!\n");
			exit(1);
		}
		set_handler();
		send_message(serverpid, argv[2]);
		while (1)
			pause();
	}
	return (0);
}
