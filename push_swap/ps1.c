/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 03:05:47 by syildiri          #+#    #+#             */
/*   Updated: 2022/03/24 03:05:52 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion(int array[], int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < i + 1)
		{
			if (array[j] > array[i])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_start_struct(t_value *s0)
{
	s0->a = NULL;
	s0->b = NULL;
	s0->d = NULL;
	s0->argsa = 0;
	s0->argsb = 0;
	s0->yak_value = 0;
	s0->doldur_a = 0;
}

void	ft_exit(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '-')
			i++;
		if (ft_isdigit(argv[i]))
			i++;
		else
		{
			printf("Error\n");
			exit(0);
		}
	}
}

void	ft_exit2(long int d)
{
	if (d > 2147483647)
	{
		printf("Error\n");
		exit(0);
	}
	if (d < -2147483648)
	{
		printf("Error\n");
		exit(0);
	}
}

void	ft_exit3(t_value *s0)
{
	int	i;

	i = 0;
	while (i <= s0->argsa - 2)
	{
		if (s0->d[i] == s0->d[i + 1])
		{
			printf("Error\n");
			exit(0);
		}
		i++;
	}
}
