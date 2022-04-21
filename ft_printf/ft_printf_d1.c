/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 05:26:23 by syildiri          #+#    #+#             */
/*   Updated: 2022/02/23 04:30:14 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	d_fon(const char *str, t_print *s0)
{
	char	*argv2;

	argv2 = ft_itoa(va_arg(s0->arg0, int));
	if (argv2[0] != '-' && s0->space != 0)
		s0->return_value += write(1, " ", 1);
	if (argv2[0] != '-' && s0->plus != 0)
		s0->return_value += write(1, "+", 1);
	if (s0->point != 0 && s0->zero != 0)
		s0->zero = 0;
	if (s0->pos != 0 && s0->point == 0 && !(ft_strchr("sdiu", s0->spec)))
		s0->pos = 0;
	if (s0->dash != 0 || s0->point != 0 || s0->zero != 0 || s0->pos != 0)
	{
		if (argv2[0] != '-' && s0->space != 0)
			s0->return_value += write(1, " ", 1);
		flag_point_neg_zero_d(str, s0, argv2);
	}
	else
		s0->return_value += write(1, argv2, ft_strlen(argv2));
	free(argv2);
}

void	flag_point_neg_zero_d(const char *str, t_print *s0, char *argv2)
{
	char	*a;
	int		*c;
	int		k;

	a = NULL;
	if (s0->zero != 0 && s0->point == 0)
		s0->point = s0->zero;
	if (ft_atoi(argv2) == 0 && s0->pos != 0 \
	&& !(ft_strchr("abcdefABCDEF", argv2[0])) && s0->point != 0)
		argv2[0] = '\0';
	middle_0_flag_point_neg_zero_d(str, s0, a, argv2);
	c = (int []){0, s0->return_value};
	middle_2_d_0(str, s0, argv2);
	middle_1_flag_point_neg_zero_d(s0, argv2, c);
	if (s0->dash != 0 && s0->point == 0)
	{
		s0->return_value += write(1, argv2, ft_strlen(argv2));
		k = s0->neg_value - ft_strlen(argv2);
		while (k-- > 0)
			s0->return_value += write(1, " ", 1);
	}
	while (s0->neg_value - s0->return_value > 0)
		s0->return_value += write(1, " ", 1);
}
