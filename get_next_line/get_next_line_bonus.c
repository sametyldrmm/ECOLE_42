/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:27:04 by syildiri          #+#    #+#             */
/*   Updated: 2022/02/17 23:32:23 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*main_line[2048];

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	main_line[fd] = read_line(fd, main_line[fd]);
	if (!main_line[fd])
	{
		return (NULL);
	}
	result_line = return_line(main_line[fd]);
	main_line[fd] = next_line(main_line[fd]);
	return (result_line);
}
/*
int main(void)
{
	int	fd3;
	int	fd2;
	int	fd1;
	fd1 = open("text1.txt",O_RDONLY);
	fd2 = open("text2.txt",O_RDONLY);
	fd3 = open("text3.txt",O_RDONLY);


	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd3));

	
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd3));
}*/