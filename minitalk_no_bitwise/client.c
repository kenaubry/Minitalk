/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:36:46 by kenaubry          #+#    #+#             */
/*   Updated: 2021/12/21 15:36:47 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	unsigned int	num;
	int				i;
	int				np;

	np = 1;
	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			np = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(np * num));
}

char	*to_binary(char c)
{
	int		nb;
	char	*res;
	int		i;

	i = 7;
	res = malloc(sizeof(char) * 9);
	res[8] = '\0';
	nb = (int)c;
	while (i)
	{
		res[i--] = (nb % 2) + '0';
		nb = (nb - (nb % 2)) / 2;
	}
	res[i] = nb + '0';
	return (res);
}

char	*join_binary(char *msg)
{
	char	*encrypted;
	int		i;

	i = 0;
	encrypted = malloc(sizeof(char) * ((ft_strlen(msg) * 8) + 1));
	encrypted[0] = '\0';
	while (msg[i])
		encrypted = ft_strcat(encrypted, to_binary(msg[i++]));
	return (encrypted);
}

void	send_msg(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			kill(pid, SIGUSR2);
		else if (str[i] == '0')
			kill(pid, SIGUSR1);
		i++;
		usleep(500);
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_putstr("Wrong number of arguments.");
		return (0);
	}
	pid = ft_atoi(av[1]);
	send_msg(pid, join_binary(av[2]));
	return (0);
}
