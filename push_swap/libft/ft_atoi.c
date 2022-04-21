/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 02:55:05 by syildiri          #+#    #+#             */
/*   Updated: 2022/03/24 03:06:28 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
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
	}
	return (value * neg_value);
}
