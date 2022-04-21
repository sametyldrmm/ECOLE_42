/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 02:15:22 by syildiri          #+#    #+#             */
/*   Updated: 2022/02/23 15:27:18 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_itoa(long int n)
{
	char			*r;
	long int		tmp;
	int				a;

	a = 1;
	tmp = n;
	while (tmp && a++)
		tmp /= 10;
	r = (char *)malloc(sizeof(char) * ((n < 0) + a + (n == 0)));
	if (!r)
		return (NULL);
	r += (n < 0) + a - 1 + (n == 0);
	*r = '\0';
	if (n == 0)
		*(--r) = '0';
	a = (n >= 0) * 2 - 1;
	while (n)
	{
		*(--r) = (n % (10 * a)) * a + '0';
		n /= 10;
	}
	if (a < 0)
		*(--r) = '-';
	return (r);
}

int	ft_atoi(const char *str)
{
	int		neg_value;
	int		i;
	long	value;

	i = 0;
	neg_value = 1;
	value = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			neg_value *= -1;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		value = value * 10 + (str[i++] - 48);
		if ((value * neg_value) < -2147483648)
			return (0);
		if ((value * neg_value) > 2147483647)
			return (-1);
	}
	return (value * neg_value);
}

char	*ft_ullitoa_base(unsigned long long int n, char *base)
{
	char					*a;
	unsigned long long int	nbr;
	size_t					size;
	int						b_len;

	b_len = ft_strlen(base);
	nbr = n;
	size = 0 + (n == 0);
	while (n)
	{
		n /= b_len;
		size++;
	}
	a = (char *)malloc(size + 1);
	if (!(a))
		return (0);
	a[size--] = '\0';
	while (nbr > 0)
	{
		a[size--] = base[nbr % b_len];
		nbr /= b_len;
	}
	if (size == 0 && a[1] == '\0')
		a[0] = '0';
	return (a);
}
