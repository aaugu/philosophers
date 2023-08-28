/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:33:00 by aaugu             #+#    #+#             */
/*   Updated: 2023/08/28 21:38:07 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include "philos.h"

void	init_philos_forks(t_philo *philo, int nb_philos);

int		init_philos(t_philo *philos, int nb_philos)
{
	int i;

	i = 0;
	while (i < nb_philos)
	{
		if (pthread_mutex_init(&philos[i].mutex, NULL) != 0)
			return (-1);
		philos[i].id = i + 1;
		philos[i].nb_meals = 0;
		init_philos_forks(&philos[i], nb_philos);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	init_philos_forks(t_philo *philo, int nb_philos)
{
	if (philo->id % 2)
	{
		philo->fork_left = philo->id - 1;
		philo->fork_right = philo->id;
	}
	else
	{
		philo->fork_left = philo->id;
		philo->fork_right = philo->id - 1;
	}
	if (philo->id == 1)
		philo->fork_right = nb_philos;
}

void	destroy_philos(t_philo *philos, int nb_philos)
{
	int	i;

	i = 0;
	while (i < nb_philos)
	{
		pthread_mutex_unlock(&philos[i].mutex);
		pthread_mutex_destroy(&philos[i].mutex);
		i++;
	}
}
