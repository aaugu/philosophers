/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:33:00 by aaugu             #+#    #+#             */
/*   Updated: 2023/09/01 11:46:57 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philos.h"
#include "utils.h"

void	init_philo_forks(t_philo *philo, int nb_philos);

int	init_philos(t_philo *philos, int nb_philos, t_table *table)
{
	int	i;

	i = 0;
	while (i < nb_philos)
	{
		if (pthread_mutex_init(&philos[i].meal_lock, NULL) != 0)
			return (msg(STR_ERR_MUTEX, "Philo", ERROR));
		philos[i].id = i;
		philos[i].nb_meals = 0;
		philos[i].table = table;
		init_philo_forks(&philos[i], nb_philos);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	init_philo_forks(t_philo *philo, int nb_philos)
{
	philo->fork_left = philo->id;
	philo->fork_right = philo->id - 1;
	if (philo->id == 0 && nb_philos != 1)
		philo->fork_right = nb_philos - 1;
}

void	destroy_philos(t_philo *philos, int nb_philos)
{
	int	i;

	i = 0;
	while (i < nb_philos)
	{
		pthread_mutex_destroy(&philos[i].meal_lock);
		i++;
	}
}
