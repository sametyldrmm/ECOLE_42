/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 03:07:24 by syildiri          #+#    #+#             */
/*   Updated: 2022/03/24 03:07:26 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	controller(t_value *s0)
{
	int	i;

	i = 0;
	while (s0->a[i] == s0->d[i])
	{
		i++;
	}
	if (i >= s0->argsa)
	{
		exit(1);
	}
}

void	isthree(t_value *s0)
{
	if (s0->d[2] != s0->a[2])
	{
		if (s0->d[2] == s0->a[0])
		{
			ft_rotate_a(s0);
		}
		else
			ft_rev_rotate_a(s0);
	}
	if (s0->a[0] > s0->a[1])
		ft_swap_a(s0);
	exit(0);
}

void	choise(t_value *s0)
{
	if (s0->argsa == 5)
		isfive(s0);
	else if (s0->argsa == 3)
		isthree(s0);
	else if (s0->argsa == 2)
	{
		if (s0->a[0] > s0->a[1])
			ft_swap_a(s0);
	}
	else
		chose_other(s0);
}

void	free0(t_value *s0)
{
	free(s0->a);
	free(s0->b);
	free(s0->d);
	free(s0);
}

int	main(int args, char **argv)
{
	t_value	*s0;
	int		*c;

	s0 = (t_value *)malloc(sizeof(t_value));
	ft_start_struct(s0);
	series_loading_choise(args, argv, s0);
	c = malloc(s0->argsa * 4);
	ft_memcpy(c, s0->a, s0->argsa * 4);
	insertion(c, s0->argsa);
	s0->d = c;
	s0->d_value = s0->argsa - 3;
	ft_exit3(s0);
	controller(s0);
	choise(s0);
	while (s0->argsb)
	{
		s0->yak_value = 0;
		ft_start(s0);
		if (s0->a[0] > s0->a[1])
			ft_swap_a(s0);
	}
	free0(s0);
}
