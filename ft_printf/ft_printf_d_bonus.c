/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 03:04:26 by syildiri          #+#    #+#             */
/*   Updated: 2022/02/23 15:26:47 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	middle_0_flag_point_neg_zero_d(const char *str, t_print *s0
			, char *a, char *argv2)
{
	if (s0->point != 0)
	{
		a = ft_substr(str, s0->point + 1, s0->spec_index - s0->point);
		s0->point_value = atoi(a);
		if (s0->point_value == 0 && s0->spec == 's')
			argv2 = "";
		free(a);
	}
	if (s0->dash != 0)
	{
		if (s0->point != 0)
		{
			a = ft_substr(str, s0->dash + 1, s0->point - s0->dash);
			s0->neg_value = atoi(a);
			free(a);
		}
		else
		{
			a = ft_substr(str, s0->dash + 1, s0->spec_index - s0->dash);
			s0->neg_value = atoi(a);
			free(a);
		}
	}
}

void	middle_1_d_0(t_print *s0, char *argv2, int *c)
{
	int	b;

	if (argv2[0] == '-' && s0->point_value != 0)
	{
		c[0] = 0;
		s0->return_value += write(1, "-", 1);
		b = -1;
		if (s0->zero != 0)
			b = 0;
		while (s0->point_value > (int)ft_strlen(argv2) + b + c[0]++)
			s0->return_value += write(1, "0", 1);
		s0->return_value += write(1, argv2 + 1, ft_strlen(argv2) - 1);
		c[0] = 0;
		if (s0->dash != 0)
			while (s0->return_value - c[1] < s0->neg_value - c[0]++)
				s0->return_value += write(1, " ", 1);
	}
}

void	middle_1_flag_point_neg_zero_d(t_print *s0
		, char *argv2, int *c)
{
	middle_1_d_0(s0, argv2, c);
	if (argv2[0] != '-' && s0->point_value != 0)
	{
		c[0] = 0;
		while (s0->point_value > (int)ft_strlen(argv2) + c[0]++)
			s0->return_value += write(1, "0", 1);
		s0->return_value += write(1, argv2, ft_strlen(argv2));
		if (s0->dash != 0)
			while (s0->return_value - c[1] < s0->neg_value - c[0]++)
				s0->return_value += write(1, " ", 1);
	}
}

void	mid_fin(t_print *s0, char *argv2)
{
	int		b;

	if ((int )ft_strlen(argv2) >= s0->point_value)
		b = s0->pos_value - ft_strlen(argv2);
	else
		b = s0->pos_value - s0->point_value -(argv2[0] == '-');
	while (b-- > 0)
		s0->return_value += write(1, " ", 1);
	if (argv2[0] == '0' && s0->point != 0)
		argv2[0] = ' ';
	if (s0->point_value == 0)
		s0->return_value += write(1, argv2, ft_strlen(argv2));
}

void	middle_2_d_0(const char *str, t_print *s0, char *argv2)
{
	char	*a;

	if (s0->pos != 0)
	{
		if (s0->point != 0)
		{
			a = ft_substr(str, s0->pos, s0->point - s0->pos);
			s0->pos_value = ft_atoi(a);
			free(a);
		}
		else
		{
			a = ft_substr(str, s0->pos, s0->spec_index - s0->pos);
			s0->pos_value = ft_atoi(a);
			free(a);
		}
		mid_fin(s0, argv2);
	}
}
