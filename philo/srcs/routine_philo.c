/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:53:41 by aaugu             #+#    #+#             */
/*   Updated: 2023/09/06 19:37:21 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "philosophers_dining.h"
#include "routines.h"
#include "utils.h"

void	*alone_routine(t_philo *philo);
void	sync_start_time(t_philo *philo);
void	eat_sleep_think(t_philo *philo);
void	philo_waiting(t_philo *philo, unsigned int waiting_time);

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	sync_start_time(philo);
	if (philo->table->nb_philos == 1)
		return (alone_routine(philo));
	if (philo->id % 2)
		philo_waiting(philo, philo->table->time_to_eat);
	while (dinner_finished(philo->table) == false)
		eat_sleep_think(philo);
	return (NULL);
}

void	sync_start_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = philo->table->start_time;
	pthread_mutex_unlock(&philo->meal_lock);
	while (get_time_in_ms() < philo->table->start_time)
		usleep(10);
}

void	*alone_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork_locks[philo->fork_left]);
	print_status(philo, FORK, get_time_in_ms());
	philo_waiting(philo, philo->table->time_to_die);
	print_status(philo, DIED, get_time_in_ms());
	pthread_mutex_unlock(&philo->table->fork_locks[philo->fork_left]);
	return (NULL);
}

void	eat_sleep_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork_locks[philo->fork_left]);
	print_status(philo, FORK, get_time_in_ms());
	pthread_mutex_lock(&philo->table->fork_locks[philo->fork_right]);
	print_status(philo, FORK, get_time_in_ms());
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->meal_lock);
	print_status(philo, EATING, get_time_in_ms());
	philo_waiting(philo, philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->table->fork_locks[philo->fork_right]);
	pthread_mutex_unlock(&philo->table->fork_locks[philo->fork_left]);
	if (dinner_finished(philo->table) == false)
	{
		pthread_mutex_lock(&philo->meal_lock);
		philo->nb_meals++;
		pthread_mutex_unlock(&philo->meal_lock);
	}
	print_status(philo, SLEEPING, get_time_in_ms());
	philo_waiting(philo, philo->table->time_to_sleep);
	print_status(philo, THINKING, get_time_in_ms());
}

void	philo_waiting(t_philo *philo, unsigned int waiting_time)
{
	unsigned int	limit;

	limit = get_time_in_ms() + waiting_time;
	while (get_time_in_ms() < limit)
	{
		if (dinner_finished(philo->table))
			break ;
		usleep(10);
	}
}
