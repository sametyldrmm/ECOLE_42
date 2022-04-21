/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 02:16:07 by syildiri          #+#    #+#             */
/*   Updated: 2022/02/23 15:27:10 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	u_fon(const char *str, t_print *s0)
{
	char			*argv2;
	unsigned int	b;

	b = va_arg(s0->arg0, unsigned int);
	argv2 = ft_itoa(b);
	if (b == 0 && s0->pos != 0 && s0->point != 0)
		argv2 = ft_strdup("\0");
	flag_point_neg_zero_d(str, s0, argv2);
	if (s0->point == 0 && s0->dash == 0 && s0->zero == 0 && s0->pos == 0)
		s0->return_value += write(1, argv2, ft_strlen(argv2));
	free(argv2);
}
