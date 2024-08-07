/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:58:09 by msalembe          #+#    #+#             */
/*   Updated: 2024/08/07 09:54:49 by mario            ###   ########.fr       */
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

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	bits;

	(void)context;
	if (sig == SIGUSR1)
		c |= (0x01 << bits);
	bits++;
	if (bits == 8)
	{
		write(1, &c, 1);
		if (c == '\n')
			kill(info->si_pid, SIGUSR1);
		c = 0;
		bits = 0;
	}
}

int	main(void)
{
	struct sigaction	sign;

	ft_putstr("Server is running...");
	printf("%d\n", getpid());
	while (1)
	{
		sign.sa_flags = SA_SIGINFO;
		sign.sa_sigaction = handle_signal;
		sigemptyset(&sign.sa_mask);
		sigaction(SIGUSR1, &sign, NULL);
		sigaction(SIGUSR2, &sign, NULL);
	}
	return (0);
}
