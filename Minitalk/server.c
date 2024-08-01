/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalembe <msalembe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:58:09 by msalembe          #+#    #+#             */
/*   Updated: 2024/06/28 01:16:49 by msalembe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

static void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	write(1, "\n", 1);
}

static void	ft_simple_putnbr(int number)
{
	if (number >= 10)
		ft_simple_putnbr(number / 10);
	write(1, &"0123456789"[number % 10], 1);
}

static void	ft_handler(int signal, siginfo_t *info, void *u_content)
{
	static int	bit;
	static int	i;

	(void)info;
	(void)u_content;
	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sign;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr("Error: wrong format");
		ft_putstr("Try: ./server");
		exit(EXIT_FAILURE);
	}
	pid = getpid();
	ft_putstr("PID:");
	ft_simple_putnbr(pid);
	write(1, "\n", 1);
	while (argc == 1)
	{
		sign.sa_sigaction = &ft_handler;
		sign.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &sign, NULL);
		sigaction(SIGUSR2, &sign, NULL);
	}
	return (0);
}
