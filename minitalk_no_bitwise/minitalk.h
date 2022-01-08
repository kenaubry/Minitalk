/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:53:21 by kenaubry          #+#    #+#             */
/*   Updated: 2021/12/21 15:53:22 by kenaubry         ###   ########.fr       */
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
size_t	ft_strlen(const char *str);
void	ft_putnbr(int n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcat(char *dest, char *src);
int		ft_atoi(const char *str);
int		ft_iterative_power(int nb, int power);
void	b_to_c(char *str);

#endif