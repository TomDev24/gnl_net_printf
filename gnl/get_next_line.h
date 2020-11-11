/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:49:07 by dbrittan          #+#    #+#             */
/*   Updated: 2020/11/11 16:12:59 by dbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
# endif

# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

int	get_next_line(const int fd, char **line);

#endif
