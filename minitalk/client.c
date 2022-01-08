/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 17:51:32 by kenaubry          #+#    #+#             */
/*   Updated: 2022/01/01 17:51:34 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char *msg, int len_msg)
{
	int		len_binary;
	int		i;

	i = 0;
	while (i <= len_msg)
	{
		len_binary = 0;
		while (len_binary < 7)
		{
			if ((msg[i] >> len_binary) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			len_binary++;
			usleep(100);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_putstr("Wrong number of arguments.\n");
		ft_putstr("Have to be \"./client\" \"PID\" \"Message to send\"\n");
		return (0);
	}
	pid = ft_atoi(av[1]);
	send_char(pid, av[2], ft_strlen(av[2]));
	return (0);
}
