/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:27:20 by syildiri          #+#    #+#             */
/*   Updated: 2022/02/17 23:49:40 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*return_line(char *main_line)
{
	char	*result_line;
	int		i;

	i = 0;
	if (!main_line[i])
		return (NULL);
	while (main_line[i] != '\n' && main_line[i])
		i++;
	result_line = (char *)malloc(sizeof(char) * i + 2);
	if (!result_line)
		return (NULL);
	i = 0;
	while (main_line[i] != '\n' && main_line[i])
	{
		result_line[i] = main_line[i];
		i++;
	}
	if (main_line[i] == '\n')
	{
		result_line[i] = '\n';
		i++;
	}
	result_line[i] = '\0';
	return (result_line);
}

char	*next_line(char *main_line)
{
	int		i;
	int		c;
	char	*satir;

	i = 0;
	while (main_line[i] != '\n' && main_line[i])
		i++;
	if (!main_line[i])
	{
		free (main_line);
		return (NULL);
	}
	satir = (char *)malloc(sizeof(char) * (ft_strlen(main_line) - i + 1));
	if (!satir)
		return (NULL);
	i++;
	c = 0;
	while (main_line[i])
		satir[c++] = main_line[i++];
	satir[c] = '\0';
	free(main_line);
	return (satir);
}

char	*read_line(int fd, char *main_line)
{
	int		read_value;
	char	*part_line;

	read_value = 1;
	part_line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!part_line)
		return (NULL);
	while (!ft_strchr(main_line, '\n') && read_value != 0)
	{
		read_value = read(fd, part_line, BUFFER_SIZE);
		if (read_value == -1)
		{
			free (part_line);
			return (NULL);
		}
		part_line[read_value] = '\0';
		main_line = ft_strjoin(main_line, part_line);
	}
	free (part_line);
	return (main_line);
}

char	*get_next_line(int fd)
{
	char		*result_line;
	static char	*main_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	main_line = read_line(fd, main_line);
	if (!main_line)
	{
		return (NULL);
	}
	result_line = return_line(main_line);
	main_line = next_line(main_line);
	return (result_line);
}
