/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 03:06:56 by syildiri          #+#    #+#             */
/*   Updated: 2022/03/24 03:07:01 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_rotate_ab(t_value *s0)
{
	ft_rotate_b(s0);
	ft_rotate_a(s0);
}

// void controller(t_value *s0)
// {
// 	int i;

// 	i = 0;
// 	while (s0->a[i] == s0->d[i])
// 	{
// 		i++;
// 	}
// 	if (i == s0->argsa)
// 	{
// 		exit(0);
// 	}
// }