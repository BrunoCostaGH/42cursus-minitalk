/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <bsilva-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:45:03 by bsilva-c          #+#    #+#             */
/*   Updated: 2023/09/04 13:35:13 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_message(pid_t serverpid, char *message, bool has_signal)
{
	static bool	p_has_signal;
	int			bits;
	char		ch;

	if (!serverpid && !message && has_signal)
	{
		p_has_signal = has_signal;
		return ;
	}
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
			while (!p_has_signal)
				;
			p_has_signal = false;
		}
		message++;
	}
}

static void	handler(int signum)
{
	(void)signum;
	send_message(0, 0, true);
}

static void	set_handler(void)
{
	struct sigaction	sa;

	sa.sa_handler = &handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
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
		send_message(serverpid, argv[2], 0);
	}
	return (0);
}
