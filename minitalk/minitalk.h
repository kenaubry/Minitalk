/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:56:41 by kenaubry          #+#    #+#             */
/*   Updated: 2022/01/01 16:56:42 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <signal.h>

void	get_pid(void);
int		ft_putchar(char c);
int		ft_putstr(const char *s);
int		ft_strlen(const char *str);
void	ft_putnbr(int n);
int		ft_atoi(const char *str);
void	get_char(int bit);
void	send_char(int pid, char *msg, int len_msg);

#endif
