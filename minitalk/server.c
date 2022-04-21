
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

char	*ft_itoa(int n)
{
	char	*r;
	int		tmp;
	int		a;

	a = 1;
	tmp = n;
	while (tmp && a++)
		tmp /= 10;
	r = (char *)malloc(sizeof(char) * ((n < 0) + a + (n == 0)));
	if (!r)
		return (NULL);
	r += (n < 0) + a - 1 + (n == 0);
	*r = '\0';
	if (n == 0)
		*(--r) = '0';
	a = (n >= 0) * 2 - 1;
	while (n)
	{
		*(--r) = (n % (10 * a)) * a + '0';
		n /= 10;
	}
	if (a < 0)
		*(--r) = '-';
	return (r);
}

void	signal_detect(int n, int client_pid)
{
	static unsigned char	value = 0;
	static int				a = 1;

	if (n == 30)
		value = value << 1;
	if (n == 31)
		value = (value << 1) | 0x01;
	if (a % 9 == 0 && a != 0)
	{
		write(1, (unsigned char *)&value, 1);
		if (value == 0)
			kill(client_pid, SIGUSR1);
		value = 0;
	}
	a++;
}

void	signal_detect1(int sign, siginfo_t *info, void *context)
{
	signal_detect(sign, info->si_pid);
}

int	main(void)
{
	struct sigaction	s_sig;
	int					k;

	k = getpid();
	write(1, ft_itoa(k), 5);
	write(1, "\n", 1);
	s_sig.sa_sigaction = signal_detect1;
	s_sig.sa_flags = SA_SIGINFO;
	sigaction (SIGUSR1, &s_sig, 0);
	sigaction (SIGUSR2, &s_sig, 0);
	while (1)
		pause();
}
