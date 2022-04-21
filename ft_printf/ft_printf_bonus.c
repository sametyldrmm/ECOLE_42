/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:44:54 by syildiri          #+#    #+#             */
/*   Updated: 2022/02/23 15:26:36 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	type_showing(const char *str, t_print *s0, int y)
{
	while (!(ft_strchr("scdipxXu", str[y])) && str[y + 1] != '%')
	{
		if (str[y] == '.')
			s0->point = y;
		if (str[y] == '-')
			s0->dash = y;
		if (str[y] == '0' && (str[y - 1] == '%' || str[y -1] == ' ' ) \
			&& (str[y + 1] >= '0' && str[y + 1] <= '9'))
				s0->zero = y;
		if (str[y] >= '0' && str[y] <= '9' && (ft_strchr("% ", str[y - 1])))
			s0->pos = y;
		if (str[y] == ' ')
			s0->space = y;
		if (str[y] == '#')
			s0->sharp = y;
		if (str[y] == '+')
			s0->plus = y;
		y++;
	}
	s0->spec_index = y;
	s0->spec = str[y];
}

t_print	*ft_start_struct(t_print *s0, int a)
{
	s0->argv1 = 0;
	s0->spec = 0;
	s0->spec_index = 0;
	s0->zero = 0;
	s0->point = 0;
	if (a)
		s0->return_value = 0;
	s0->point_value = 0;
	s0->neg_value = 0;
	s0->dash = 0;
	s0->pos = 0;
	s0->pos_value = 0;
	s0->space = 0;
	s0->plus = 0;
	s0->sharp = 0;
	return (s0);
}

void	type_target(const char *str, t_print *s0, int i)
{
	type_showing(str, s0, i);
	if (s0->spec == 's')
		s_fon(str, s0);
	if (s0->spec == 'c')
		c_fon(str, s0);
	if (s0->spec == 'd' || s0->spec == 'i')
		d_fon(str, s0);
	if (s0->spec == 'x' || s0->spec == 'X')
		x_fon(str, s0);
	if (s0->spec == 'u')
		u_fon(str, s0);
	if (s0->spec == 'p')
		p_fon(str, s0);
	if (s0->spec == '%')
		s0->return_value += write(1, "%", 1);
	if (s0->argv1)
		free(s0->argv1);
	ft_start_struct(s0, 0);
}

void	ft_printf_middle(const char *str, t_print *s0)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			type_target(str, s0, i);
			if (str[i + 1] == '%')
				i += 1;
			else
				while (!(ft_strchr("scdipxXu", str[i])))
					i++;
		}
		else
			s0->return_value += write(1, &str[i], 1);
		i++;
	}
}

int	ft_printf(const char *str, ...)
{
	int		return_value0;
	t_print	*s0;

	s0 = (t_print *)malloc(sizeof(t_print));
	if (!s0)
		return (-1);
	ft_start_struct(s0, 1);
	va_start(s0->arg0, str);
	ft_printf_middle(str, s0);
	va_end(s0->arg0);
	return_value0 = s0->return_value;
	if (s0->argv1)
		free(s0->argv1);
	free(s0);
	return (return_value0);
}
