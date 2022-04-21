/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:52:12 by syildiri          #+#    #+#             */
/*   Updated: 2022/02/23 15:27:33 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	x_fon(const char *str, t_print *s0)
{
	char			*argv2;
	unsigned int	b;

	b = va_arg(s0->arg0, unsigned int);
	if (s0->sharp != 0 && b != 0 && s0->spec == 'x')
	{
		s0->return_value += write(1, "0x", 2);
	}
	if (s0->sharp != 0 && b != 0 && s0->spec == 'X')
	{
		s0->return_value += write(1, "0X", 2);
	}
	if (s0->spec == 'x')
		argv2 = ft_ullitoa_base(b, HEXADOWN);
	else
		argv2 = ft_ullitoa_base(b, HEXAUPP);
	flag_point_neg_zero_d(str, s0, argv2);
	if (s0->point == 0 && s0->dash == 0 && s0->zero == 0 && s0->pos == 0)
		s0->return_value += write(1, argv2, ft_strlen(argv2));
	free(argv2);
}
