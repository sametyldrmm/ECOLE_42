/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 03:05:57 by syildiri          #+#    #+#             */
/*   Updated: 2022/03/24 05:45:23 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	series_loading_choise(int args, char **argv, t_value *s0)
{
	int	i;

	i = 0;
	s0->argsa = arg_say(args, argv, s0);
	s0->a = malloc(s0->argsa * 4);
	s0->b = malloc(s0->argsa * 4);
	while (args - i -1 > 0)
	{
		if (bak(argv[i + 1], ' '))
		{
			dizi_doldurma1(argv, s0, i);
		}
		else
		{
			dizi_doldurma(argv, s0, i);
		}
	i++;
	}
}

int	a_da_varmi(t_value *s0, int arg)
{
	int	i;

	i = 0;
	while (i <= s0->argsa - 1)
	{
		if (arg >= s0->a[i])
			return (i);
		i++;
	}
	return (-1);
}

void	b_pus(t_value *s0, int arg1)
{
	while (a_da_varmi(s0, arg1) != -1)
	{
		if (s0->a[0] <= arg1)
		{
			ft_push_b(s0);
		}
		else
			ft_rotate_a(s0);
	}
}

int	position_start(t_value *s0)
{
	int	i;

	i = 0;
	s0->d_value = s0->argsa + s0->argsb - 1;
	while (s0->d[s0->d_value] == s0->a[s0->argsa - i - 1]
		&& s0->argsa > 0 && s0->d_value > 0)
	{
		s0->d_value--;
		i++;
	}
	return (s0->d_value);
}

int	posision_start(t_value *s0, int k)
{
	int	i;

	i = 0;
	while (1)
	{
		if (s0->d[k] == s0->b[i] && s0->argsb >= i)
		{
			return (i);
		}
		i++;
	}
}
