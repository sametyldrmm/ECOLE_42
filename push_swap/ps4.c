/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 03:06:03 by syildiri          #+#    #+#             */
/*   Updated: 2022/03/24 03:06:08 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	posision_up(t_value *s0, int c)
{
	int	i;
	int	k;

	i = 0;
	k = position_start(s0);
	while (c-- > 0)
		ft_rotate_b(s0);
	ft_push_a(s0);
}

void	posision_down(t_value *s0, int b)
{
	int	i;
	int	k;

	k = position_start(s0);
	i = 0;
	while (b-- > 0)
	{
		ft_rev_rotate_b(s0);
		if (s0->b[0] == s0->d[k - 1] && k > 3 && s0->b[0] != 0)
			ft_push_a(s0);
		if (s0->b[0] == s0->d[k - 2] && k > 3 && s0->b[0] != 0)
		{
			ft_push_a(s0);
			ft_rotate_a(s0);
			i++;
		}
	}
	ft_push_a(s0);
	if (s0->a[0] > s0->a[1])
		ft_swap_a(s0);
	if (i == 1)
		ft_rev_rotate_a(s0);
}

void	ft_start(t_value *s0)
{
	int	c;

	c = posision_start(s0, position_start(s0));
	if (s0->a[0] > s0->a[1])
		ft_swap_a(s0);
	if (c == 0)
	{
		ft_push_a(s0);
		if (s0->a[0] > s0->a[1])
			ft_swap_a(s0);
	}
	else if (c <= s0->argsb / 2)
	{
		posision_up(s0, c);
		if (s0->a[0] > s0->a[1])
			ft_swap_a(s0);
	}
	else if (c > s0->argsb / 2)
	{
		c = s0->argsb - c;
		posision_down(s0, c);
		if (s0->a[0] > s0->a[1])
			ft_swap_a(s0);
	}
}

void	chose_other(t_value *s0)
{
	int		i;
	float	k;
	int		b;

	i = 0;
	k = (130 - (s0->argsa + s0->argsb) * 0.1) / 400 ;
	while (i++ < 50)
	{
		b = (s0->argsa -2) * k + s0->argsb;
		b_pus(s0, s0->d[b]);
	}
	if (s0->a[0] > s0->a[1])
		ft_swap_a(s0);
}

void	isfive(t_value *s0)
{
	b_pus(s0, s0->d[1]);
	if (s0->b[0] < s0->b[1])
		ft_swap_b(s0);
	while (s0->d[4] != s0->a[2])
	{
		ft_rotate_a(s0);
	}
	if (s0->a[0] > s0->a[1])
		ft_swap_a(s0);
	while (s0->argsb)
	{
		ft_push_a(s0);
	}
	exit(0);
}
