#include <libc.h>
#include <stdlib.h>
#include <unistd.h>

void	handler(int sig, siginfo_t *info, void *ctx)
{
	int						bit;
	int						i;
	static unsigned char	uc = 0;
	static int				test = 0;

	bit = sig - 30;
	if (bit)
		bit = 64;
	uc = uc | bit;
	if (test == 6)
	{
		test = 0;
		write(1, &uc, 1);
		uc = 0;
		return ;
	}
	uc = uc >> 1;
	test++;
}

int	main(void)
{
	struct sigaction	act;
	pid_t				pid;

	pid = getpid();
	printf("%d\n", pid);
	bzero(&act, sizeof(struct sigaction));
	act.sa_sigaction = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
	{
	}
	return (0);
}
