/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:50:11 by dbrittan          #+#    #+#             */
/*   Updated: 2020/11/09 19:35:19 by dbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(const int fd, char **line)
{
	char buffer[BUFF_SIZE + 1];	
	int	gt_bytes;
	char *cut;
	int flag;
	static char *left;

	flag = 1;
	if (left)
		*line = ft_strdup(left);
	else
		*line = ft_calloc(1, sizeof(char));
	while (flag && (gt_bytes = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[gt_bytes] = '\0';
		if (*(cut = ft_strchr(buffer, '\n')) != '\0')
		{
			left = ft_strdup(cut + 1);
			*cut = '\0';
			flag = 0;
				
		}
		*line = ft_strjoin(*line, buffer);
	}
	
	/*while(read(fd, buffer, BUFF_SIZE)) // place for null byte
	{
		if (errno != 0)
			return (-1);
	} */
	return (0);
}

int	main(int argc, char **argv)
{
	char *res = "";
	int fd;
	
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		get_next_line(fd, &res);	
	}
	get_next_line(fd, &res);
	printf("Val is: %s", res);
	return (0);
}
