/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:50:11 by dbrittan          #+#    #+#             */
/*   Updated: 2020/11/13 15:41:20 by dbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	what_left(char **res, char **left)
{
	char *cut;

	if (**left && (cut = ft_strchr(*left, '\n')))
	{
		*cut = '\0';
		*res = ft_strdup(*left);
		if ((cut + 1))
			*left = ft_strdup(cut + 1);
		return (1);	
	} else if (**left)
	{
		*res = ft_strdup(*left);
		return (0);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char buffer[BUFFER_SIZE + 1];	
	int	got_bytes;
	char *cut;
	//int flag;
	static char *left;

	flag = 1;
	if (left && *left) // i cant check like *left got it
	{
		if (what_left(line, &left))
			return (1);	
	}
	else
		*line = ft_calloc(1, sizeof(char));

	while ((got_bytes = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[got_bytes] = '\0';
		if ((cut = ft_strchr(buffer, '\n')))
		{
			//if ((cut + 1))
			left = ft_strdup(cut + 1);
			*cut = '\0';
			*line = ft_strjoin(*line, buffer)
			return (1);
			//flag = 0;
				
		}
		*line = ft_strjoin(*line, buffer);
	}
	
	return (0);
}

int	main(int argc, char **argv)
{
	char *res = "";
	int fd;

	fd = 0;	
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		get_next_line(fd, &res);	
	}

	get_next_line(fd, &res);
	get_next_line(fd, &res);
	//get_next_line(fd, &res);	
	printf("Val is: %s", res);
	return (0);
} 
