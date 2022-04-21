/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 03:06:47 by syildiri          #+#    #+#             */
/*   Updated: 2022/03/24 03:06:48 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_swap_a(t_value *s0)
{
	int	value0 ;
	int	value1 ;

	if (s0->argsa <= 1)
		return ;
	value0 = s0->a[0];
	value1 = s0->a[1];
	s0->a[1] = value0 ;
	s0->a[0] = value1 ;
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_value *s0)
{
	int	value0 ;
	int	value1 ;

	if (s0->argsa <= 1)
		return ;
	value0 = s0->b[0];
	value1 = s0->b[1];
	s0->b[1] = value0 ;
	s0->b[0] = value1 ;
	write(1, "sb\n", 3);
}

void	ft_swap_ab(t_value *s0)
{
	ft_swap_a(s0);
	ft_swap_b(s0);
}

void	ft_push_b(t_value *s0)
{
	int	d ;
	int	d1 ;

	s0->b[s0->argsb] = s0->a[0];
	d1 = s0->b[s0->argsb];
	ft_memmove(s0->b +1, s0->b, s0->argsb * 4);
	s0->b[0] = d1;
	s0->argsb++;
	d = s0->a[0];
	ft_memmove(s0->a, s0->a + 1, s0->argsa * 4);
	s0->a[s0->argsa -1] = d;
	s0->argsa = s0->argsa -1;
	write(1, "pb\n", 3);
}

void	ft_push_a(t_value *s0)
{
	int	d;
	int	d4;

	s0->a[s0->argsa] = s0->b[0];
	d = s0->b[0];
	ft_memmove(s0->b, s0->b + 1, s0->argsb * 4);
	s0->b[s0->argsb] = d;
	s0->argsa += 1;
	d4 = s0->a[s0->argsa -1];
	ft_memmove(s0->a + 1, s0->a, s0->argsa * 4);
	s0->a[0] = d4;
	s0->argsb = s0->argsb -1;
	write(1, "pa\n", 3);
}
