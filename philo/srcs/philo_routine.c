/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:53:41 by aaugu             #+#    #+#             */
/*   Updated: 2023/08/31 15:19:21 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "philosophers_dining.h"
#include "routines.h"
#include "print_status.h"
#include "utils.h"

void	*alone_routine(t_philo *philo);
void	sync_start_time(t_philo *philo);
void	philo_waiting(t_philo *philo, unsigned int time_to_type);

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->table->nb_philos == 1)
		return (alone_routine(philo));
	sync_start_time(philo);
	return (NULL);
}

void	*alone_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork_locks[philo->fork_left]);
	print_status(philo, FORK);
	philo_waiting(philo, philo->table->time_to_die);
	print_status(philo, DIED);
	pthread_mutex_unlock(&philo->table->fork_locks[philo->fork_left]);
	return (NULL);
}

void	philo_waiting(t_philo *philo, unsigned int time_to_type)
{
	unsigned int	limit;

	limit = get_time_in_ms() + time_to_type;
	while (get_time_in_ms() < limit)
	{
		if (philo->table->stop == true)
			break ;
		usleep(1000);
	}
}

void	sync_start_time(t_philo *philo)
{
	unsigned int	time;

	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = philo->table->start_time;
	pthread_mutex_unlock(&philo->meal_lock);
	while (true)
	{
		time = get_time_in_ms();
		if (time >= philo->table->start_time)
			break ;
	}
}

void	eat_sleep(void);
void	think(void);