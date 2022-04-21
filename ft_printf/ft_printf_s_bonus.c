/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 02:19:00 by syildiri          #+#    #+#             */
/*   Updated: 2022/02/23 15:27:07 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	middle_flag_point_and_neg_s(const char *str, t_print *s0)
{
	char	*a;

	if (s0->dash != 0)
	{
		if (s0->point != 0)
		{
			a = ft_substr(str, s0->dash + 1, s0->point - s0->dash);
			s0->neg_value = ft_atoi(a);
			free(a);
		}
		else
		{
			a = ft_substr(str, s0->dash + 1, s0->spec_index - s0->dash);
			s0->neg_value = ft_atoi(a);
			free(a);
		}
	}
}

void	middle_2_flag_point_and_neg_s(const char *str, t_print *s0)
{
	char	*a;
	int		b;

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
		b = s0->pos_value - ft_strlen(s0->argv1);
		while (b-- > 0)
			s0->return_value += write(1, " ", 1);
	}
}

void	middle_3_flag_point_and_neg_s(t_print *s0)
{
	char	*a;

	if (s0->point_value != 0)
	{
		a = ft_strdup(s0->argv1);
		if (s0->argv1)
		{
			free(s0->argv1);
		}
		s0->argv1 = ft_substr(a, 0, s0->point_value);
		free(a);
	}
}

void	flag_point_and_neg_s(const char *str, t_print *s0)
{
	char	*a;
	int		b;

	if (s0->point != 0)
	{
		a = ft_substr(str, s0->point + 1, s0->spec_index - s0->point);
		s0->point_value = ft_atoi(a);
		if (s0->point_value == 0)
		{
			if (s0->argv1)
				free(s0->argv1);
			s0->argv1 = ft_strdup("");
		}
		free(a);
	}
	middle_flag_point_and_neg_s(str, s0);
	middle_3_flag_point_and_neg_s(s0);
	middle_2_flag_point_and_neg_s(str, s0);
	s0->return_value += write(1, s0->argv1, ft_strlen(s0->argv1));
	b = s0->neg_value - ft_strlen(s0->argv1);
	while (b-- > 0)
		s0->return_value += write(1, " ", 1);
}

void	s_fon(const char *str, t_print *s0)
{
	if (s0->argv1)
	{
		free(s0->argv1);
	}
	s0->argv1 = ft_strdup(va_arg(s0->arg0, char *));
	if (s0->argv1 == NULL)
	{
		s0->argv1 = ft_strdup("(null)");
	}
	if (s0->dash != 0 || s0->point != 0 || s0->pos != 0)
	{
		flag_point_and_neg_s(str, s0);
	}
	else if (s0->argv1)
		s0->return_value += write(1, s0->argv1, ft_strlen(s0->argv1));
}
