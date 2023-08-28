/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:39:40 by aaugu             #+#    #+#             */
/*   Updated: 2023/08/28 11:59:05 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include "input_checks.h"

bool	is_numerical(char *str);
int		ft_atoui(const char *str);

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
		if (i != 1 && (nb <= 60 || nb == -1))
		{
			printf("Invalid input of time.");
			return (false);
		}
		i++;
	}
	return (true);
}

int	ft_atoui(const char *str)
{
	unsigned long int	i;
	int					result;

	i = 0;
	result = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (result > INT_MAX)
		return (-1);
	return (result);
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
