/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 17:51:38 by kenaubry          #+#    #+#             */
/*   Updated: 2022/01/01 17:51:42 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	display_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr("PID : ");
	ft_putnbr(pid);
	ft_putchar('\n');
}

void	get_char(int bit)
{
	static char	c = 0;
	static int	size = 0;

	c = c + ((bit & 1) << size);
	size++;
	if (size == 7)
	{
		ft_putchar(c);
		if (!c)
			ft_putchar('\n');
		c = 0;
		size = 0;
	}
}

int	main(void)
{
	display_pid();
	while (1)
	{
		signal(SIGUSR1, get_char);
		signal(SIGUSR2, get_char);
		pause();
	}
	return (0);
}
