
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>

int	ft_atoi(char *str)
{
	int	sum;
	int	sign;
	int	found;

	sum = 0;
	sign = 1;
	found = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' \
	|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && found)
	{
		if (*str >= '0' && *str <= '9')
			sum = sum * 10 + *str - '0';
		else
			found = 0;
		str++;
	}
	return (sign * sum);
}

void	message(int a)
{
	write(1, "SUCCESS", 8);
}

int	ft_isalpha(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if ((c[i] >= 97 && c[i] <= 122) || (c[i] >= 65 && c[i] <= 97))
			return (0);
		i++;
	}
	return (1);
}

void	process(int k, int g, char *byte, char b, int j)
{
	int	i;
	int	a;

	while (g--)
	{
		i = 8;
		while (0 <= i)
		{
			a = (b >> i) & 0x01;
			if (a == 0)
				kill(k, SIGUSR1);
			else
				kill(k, SIGUSR2);
			usleep(100);
			if (i == 0)
			{
				j++;
				b = byte[j];
			}
			i--;
		}
		signal(SIGUSR1, message);
	}
}

int	main(int args, char **argv)
{
	int		k;
	int		g;
	char	*byte;
	char	b;
	int		j;

	if (args != 3 || !ft_isalpha(argv[1]))
	{
		write(1, "ERROR!! ", 9);
		return (0);
	}
	k = ft_atoi(argv[1]);
	byte = argv[2];
	j = 0;
	b = byte[j];
	g = strlen(byte) + 1;
	process(k, g, byte, b , j);
}
