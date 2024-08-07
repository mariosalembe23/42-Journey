/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:05:14 by msalembe          #+#    #+#             */
/*   Updated: 2024/08/07 09:54:55 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	write(1, "\n", 1);
}

static int	ft_atoi(const char *str)
{
	int	cnt;
	int	neg;
	int	num;

	cnt = 0;
	neg = 1;
	num = 0;
	if (!str)
		return (0);
	while ((str[cnt] >= '\t' && str[cnt] <= '\r') || str[cnt] == ' ')
		cnt++;
	if (str[cnt] == '-')
		neg = -1;
	if (str[cnt] == '+' || str[cnt] == '-')
		cnt++;
	while (str[cnt] >= '0' && str[cnt] <= '9')
	{
		num = (str[cnt] - '0') + (num * 10);
		cnt++;
	}
	return (num * neg);
}

static void	ft_send_bits(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

static void	handle_ack(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr("The message was sent right! Well Done");
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = -1;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		signal(SIGUSR1, handle_ack);
		while (argv[2][++i] != '\0')
			ft_send_bits(pid, argv[2][i]);
		ft_send_bits(pid, '\n');
	}
	else
	{
		ft_putstr("Error: wrong format!");
		ft_putstr("Try: ./client [PID] [MESSAGE]");
		return (1);
	}
	return (0);
}
