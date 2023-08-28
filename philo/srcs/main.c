/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:08:44 by aaugu             #+#    #+#             */
/*   Updated: 2023/08/23 17:37:35 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philosophers.h"

int	main(int ac, char **av)
{
	int	exit_code;

	if (ac < 5 || ac > 6)
	{
		if (ac < 5)
			printf("Error: Not enough arguments.");
		else
			printf("Error: Too much arguments.");
		return (1);
	}
	else
	{
		exit_code = philosophers(ac, av);
		return (exit_code);
	}
}
