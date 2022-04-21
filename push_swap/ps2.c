/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 03:05:53 by syildiri          #+#    #+#             */
/*   Updated: 2022/03/24 05:43:08 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dizi_doldurma(char **argv, t_value *s0, int i)
{
	long int	u;

	ft_exit(argv[i + 1]);
	u = ft_atoi(argv[i + 1]);
	ft_exit2(u);
	s0->a[s0->doldur_a] = (int)u;
	s0->doldur_a++;
	i++;
}

size_t	w_c(char const *s, char c)
{
	size_t	r;

	r = 0;
	while (*s != '\0')
	{
		if (*s != c && (s[1] == '\0' || s[1] == c))
			r++;
		s++;
	}
	return (r);
}

void	dizi_doldurma1(char **argv, t_value *s0, int d)
{
	char		**s;
	int			i;
	long int	u;

	i = 0;
	s = ft_split(argv[d + 1], ' ');
	while (s[i])
	{
		ft_exit(s[i]);
		u = ft_atoi(s[i]);
		ft_exit2(u);
		free(s[i]);
		s0->a[s0->doldur_a] = (int)u;
		s0->doldur_a++;
		i++;
	}
	free(s);
}

int	bak(char *arg, char c)
{
	int	i;

	i = 0;
	while (arg[i] != c && arg[i] != '\0')
		i++;
	if (arg[i] == '\0')
		return (0);
	else
		return (1);
}

int	arg_say(int args, char **argv, t_value *s0)
{
	int	i ;

	i = 0;
	while (args - i -1 > 0)
	{
		if (bak(argv[i + 1], ' '))
			s0->argsa += w_c(argv[i + 1], ' ');
		else
			s0->argsa++;
		i++;
	}
	return (s0->argsa);
}
