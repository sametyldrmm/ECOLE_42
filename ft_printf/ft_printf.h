/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 03:23:34 by syildiri          #+#    #+#             */
/*   Updated: 2022/02/23 04:56:16 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define  HEXAUPP	"0123456789ABCDEF"
# define HEXADOWN 	"0123456789abcdef"

typedef struct s_print
{
	va_list	arg0;
	char	*argv1;
	char	spec;
	int		spec_index;
	int		zero;
	int		point;
	int		dash;
	int		return_value;
	int		point_value;
	int		neg_value;
	int		pos;
	int		pos_value;
	int		space;
	int		sharp;
	int		plus;
}	t_print;

typedef struct s_d
{
	int	c;
	int	d;
}	t_p;
int		ft_printf(const char *str,	...);

void	c_fon(const char *str, t_print *struct0);

void	middle_0_flag_point_neg_zero_d(const char *str, t_print *struct0,
			char *a, char *argv2);

void	middle_1_flag_point_neg_zero_d(
			t_print *struct0, char *argv2, int *c);

void	flag_point_neg_zero_d(const char *str, t_print *struct0, char *argv2);

void	d_fon(const char *str, t_print *struct0);

void	p_fon(const char *str, t_print *struct0);

void	middle_flag_point_and_neg_s(const char *str, t_print *struct0);

void	middle_2_flag_point_and_neg_s(const char *str, t_print *s0);

void	flag_point_and_neg_s(const char *str, t_print *struct0);

void	s_fon(const char *str, t_print *struct0);

void	u_fon(const char *str, t_print *struct0);

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s1);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strchr(const char *s, int c);

void	x_fon(const char *str, t_print *struct0);

void	type_showing(const char *str, t_print *struct0, int y);

void	type_target(const char *str, t_print *struct0, int i);

void	ft_printf_middle(const char *str, t_print *struct0);

char	*ft_itoa(long int n);

int		ft_atoi(const char *str);

char	*ft_ullitoa_base(unsigned long long int n, char *base);

void	middle_1_d_0(t_print *struct0, char *argv2, int *c);

void	middle_2_d_0(const char *str, t_print *s0, char *argv2);

void	mid_fin(t_print *s0, char *argv2);

void	dash_and_pos(const char *str, t_print *s0);

void	middle_3_flag_point_and_neg_s(t_print *s0);

#endif