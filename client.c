/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakabay <stakabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 00:06:02 by stakabay          #+#    #+#             */
/*   Updated: 2021/12/01 00:22:26 by stakabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

pid_t		g_pid;

void	send_char(char c)
{
	int				bit;
	int				i;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = 0;
	while (i < 7)
	{
		usleep(10000);
		bit = uc & 0x01;
		if (kill(g_pid, SIGUSR1 + bit) == -1)
		{
			write(1, "Error : kill error\n", 19);
			exit(1);
		}
		uc = uc >> 1;
		i++;
	}
}

void	handler(int sig, siginfo_t *info, void *ctx)
{
	(void)sig;
	(void)info;
	(void)ctx;
	if (kill(g_pid, SIGINT) == -1)
		write(1, "Error : SIGINT error\n", 21);
	exit(1);
}

int	main(int ac, char **av)
{
	int					i;
	struct sigaction	act;

	if (ac != 3)
	{
		write(1, "Error : Need 3 args\n", 20);
		return (1);
	}
	g_pid = (pid_t)ft_atoi(av[1]);
	ft_bzero(&act, sizeof(struct sigaction));
	act.sa_sigaction = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGINT, &act, NULL) == -1)
	{
		write(1, "Error : sigact error\n", 21);
		return (1);
	}
	while (av[2][i])
	{
		send_char(av[2][i]);
		i++;
	}
	send_char('\n');
	return (0);
}
