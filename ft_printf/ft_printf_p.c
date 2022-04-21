/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 02:20:31 by syildiri          #+#    #+#             */
/*   Updated: 2022/02/22 12:09:57 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	k9(char *argv2, t_print *s0, const char *str)
{
	int		k;
	char	*a;

	if (s0->pos != 0)
	{
		a = ft_substr(str, s0->pos, s0->spec_index - s0->pos);
		s0->pos_value = ft_atoi(a);
		free(a);
	}
	if (s0->pos_value != 0)
	{
		k = s0->pos_value - ft_strlen(argv2);
		while (k-- > 2)
			s0->return_value += write(1, " ", 1);
	}	
}

void	p_fon(const char *str, t_print *s0)
{
	int			k;
	char		*a;
	char		*argv2;

	argv2 = ft_ullitoa_base(va_arg(s0->arg0, unsigned long), HEXADOWN);
	k9(argv2, s0, str);
	if (argv2)
	{
		s0->return_value += write(1, "0x", 2);
		s0->return_value += write(1, argv2, ft_strlen(argv2));
	}
	if (s0->dash != 0)
	{
		a = ft_substr(str, s0->dash + 1, s0->spec_index - s0->dash);
		s0->neg_value = ft_atoi(a);
		free(a);
	}
	if (s0->neg_value != 0)
	{
		k = s0->neg_value - ft_strlen(argv2);
		while (k-- > 2)
			s0->return_value += write(1, " ", 1);
	}
	free(argv2);
}
