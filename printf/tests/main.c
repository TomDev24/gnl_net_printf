/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:20:47 by dbrittan          #+#    #+#             */
/*   Updated: 2020/11/26 14:56:55 by dbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#include <stdio.h>

int main (int argc, char **argv)
{
	int a;
	if (argc == 10 && argv)
		a = 1;

	ft_printf("The letter:%X and another string %s yes\n", 15, "IT");
	printf("The letter %X", 15);
	return (0);
}
