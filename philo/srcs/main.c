/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:08:44 by aaugu             #+#    #+#             */
/*   Updated: 2023/08/28 20:47:23 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "philosophers_dining.h"
#include "utils.h"

bool	is_input_valid(int ac, char **av);
bool	is_numerical(char *str);

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		printf("Error: Wrong number of arguments.");
		return (EXIT_FAILURE);
	}
	else
	{
		if (is_input_valid(ac, av) == false)
			return (EXIT_FAILURE);
		return (philosophers_dining(ac, av));
	}
}

bool	is_input_valid(int ac, char **av)
{
	int	i;
	int	nb;

	i = 1;
	while (i < ac)
	{
		if (!is_numerical(av[i]))
		{
			printf("%s is not numerical.", av[i]);
			return (false);
		}
		nb = ft_atoui(av[i]);
		if (i == 1 && (nb < 1 || nb > 200))
		{
			printf("Wrong number of philosophers.");
			return (false);
		}
		if (i != 1 && (nb <= 0))
		{
			printf("%s: Invalid input of time.", av[i]);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	is_numerical(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}
