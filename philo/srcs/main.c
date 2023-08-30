/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:08:44 by aaugu             #+#    #+#             */
/*   Updated: 2023/08/30 17:20:17 by aaugu            ###   ########.fr       */
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
		return (msg("Error: Wrong number of arguments.", NULL, EXIT_FAILURE));
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
			return (msg("Not numerical.", av[i], false));
		nb = ft_atoui(av[i]);
		if (i == 1 && (nb < 1 || nb > MAX_PHILOS))
			return (msg("Wrong number of philosophers", NULL, false));
		if (i != 1 && (nb <= 0))
			return (msg("Invalid input of time.", av[i], false));
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
