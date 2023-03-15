/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <bsilva-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:45:03 by bsilva-c          #+#    #+#             */
/*   Updated: 2023/03/15 19:20:07 by bsilva-c         ###   ########.fr       */
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
		send_message(serverpid, argv[2]);
	}
	return (0);
}
