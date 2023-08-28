/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:39:40 by aaugu             #+#    #+#             */
/*   Updated: 2023/08/23 17:49:26 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft_utils.h"

int	are_input_num(int ac, char **av);
int	is_num(char *str);
int	ft_strcmp(const char *s1, const char *s2);
int	are_time_input_valid(char **av);

int	input_checks(int ac, char **av)
{
	if (!are_input_num(ac, av))
		return (-1);
	if (ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 200)
	{
		printf("Wrong number of philosophers");
		return (-1);
	}
	if (!are_time_input_valid(av))
		return (-1);
	if (ac == 6)
	{
		if (ft_atoi(av[5]) < 1)
		{
			printf("Number of time eating should be at least one");
			return (-1);
		}
	}
	return (0);
}

int	are_input_num(int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (!is_num(av[i]))
		{
			printf("%s is not numerical", av[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_num(char *str)
{
	char	*str_n;

	str_n = ft_itoa(ft_atoi(str));
	if (!str_n)
		return (0);
	if (!ft_strcmp(str, str_n))
	{
		free(str_n);
		return (1);
	}
	free(str_n);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	are_time_input_valid(char **av)
{
	if (ft_atoi(av[2]) < 60)
	{
		printf("Invalid time to death");
		return (0);
	}
	if (ft_atoi(av[3]) < 60)
	{
		printf("Invalid time to eat");
		return (0);
	}
	if (ft_atoi(av[4]) < 60)
	{
		printf("Invalid time to sleep");
		return (0);
	}
	return (1);
}
