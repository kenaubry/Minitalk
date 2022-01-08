/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:36:52 by kenaubry          #+#    #+#             */
/*   Updated: 2021/12/21 15:36:54 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		result = result * nb;
		power--;
	}
	return (result);
}

void	display_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr("PID : ");
	ft_putnbr(pid);
	ft_putchar('\n');
}

void	b_to_c(char *str)
{
	int	i;
	int	c;
	int	pow;

	i = 0;
	while (str[i])
	{
		c = 0;
		pow = 7;
		while (pow >= 0)
		{
			c = c + (str[i] - 48) * ft_iterative_power(2, pow);
			i++;
			pow--;
		}
		ft_putchar(c);
	}
}

void	handler_msg(int sig)
{
	char		carac[9];
	static int	i = 0;

	carac[8] = '\0';
	if (sig == SIGUSR2)
		carac[i] = '1';
	else if (sig == SIGUSR1)
		carac[i] = '0';
	i++;
	if (i == 8)
	{
		i = 0;
		b_to_c(carac);
	}
}

int	main(void)
{
	display_pid();
	while (1)
	{
		signal(SIGUSR1, handler_msg);
		signal(SIGUSR2, handler_msg);
		pause();
	}
	return (0);
}
