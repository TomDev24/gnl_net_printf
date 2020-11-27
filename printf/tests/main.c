/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:20:47 by dbrittan          #+#    #+#             */
/*   Updated: 2020/11/27 18:56:37 by dbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#include <stdio.h>

int main (int argc, char **argv)
{
	int a;
	//static char *s_hidden = "hi low\0don't print me lol\0";

	if (argc == 10 && argv)
		a = 1;
	
	ft_printf("%7x\n", 33);
	printf("%7x\n", 33);
	return (0);
}
