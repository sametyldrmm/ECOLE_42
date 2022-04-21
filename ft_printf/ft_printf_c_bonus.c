/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 03:04:14 by syildiri          #+#    #+#             */
/*   Updated: 2022/02/23 15:26:40 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	dash_and_pos(const char *str, t_print *s0)
{
	char	*a;
	int		b;

	if (s0->dash != 0)
	{
		a = ft_substr(str, s0->dash + 1, s0->spec_index - s0->dash);
		s0->neg_value = ft_atoi(a);
		free(a);
	}
	if (s0->pos != 0)
	{
		a = ft_substr(str, s0->pos, s0->spec_index - s0->pos);
		s0->pos_value = ft_atoi(a);
		free(a);
		b = s0->pos_value - 1;
		while (b-- > 0)
			s0->return_value += write(1, " ", 1);
	}
}

void	c_fon(const char *str, t_print *s0)
{
	char	argv2;
	int		b;

	argv2 = va_arg(s0->arg0, int);
	dash_and_pos(str, s0);
	b = 1;
	if (s0->neg_value > 1)
	{
		s0->return_value += write(1, &argv2, 1);
		while (s0->neg_value > b++)
		{
			s0->return_value += write(1, " ", 1);
		}
	}
	else
		s0->return_value += write(1, &argv2, 1);
}
