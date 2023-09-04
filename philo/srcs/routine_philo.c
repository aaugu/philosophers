/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:53:41 by aaugu             #+#    #+#             */
/*   Updated: 2023/09/04 14:03:12 by aaugu            ###   ########.fr       */
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
void	philo_waiting(unsigned int waiting_time);
void	think(t_philo *philo);

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	philo->last_meal = philo->table->start_time;
	while (get_time_in_ms() < philo->table->start_time)
		continue ;
	if (philo->table->nb_philos == 1)
		return (alone_routine(philo));
	if (philo->id % 2)
		usleep(philo->table->time_to_eat * 1000);
	while (dinner_finished(philo->table) == false)
	{
		eat_sleep_think(philo);
	}
	return (NULL);
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

void	*alone_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork_locks[philo->fork_left]);
	print_status(philo, FORK);
	philo_waiting(philo->table->time_to_die);
	print_status(philo, DIED);
	pthread_mutex_unlock(&philo->table->fork_locks[philo->fork_left]);
	return (NULL);
}

void	eat_sleep_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork_locks[philo->fork_left]);
	print_status(philo, FORK);
	pthread_mutex_lock(&philo->table->fork_locks[philo->fork_right]);
	print_status(philo, FORK);
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->meal_lock);
	print_status(philo, EATING);
	philo_waiting(philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->table->fork_locks[philo->fork_left]);
	pthread_mutex_unlock(&philo->table->fork_locks[philo->fork_right]);
	if (dinner_finished(philo->table))
	{
		pthread_mutex_lock(&philo->meal_lock);
		philo->nb_meals++;
		pthread_mutex_unlock(&philo->meal_lock);
	}
	print_status(philo, SLEEPING);
	philo_waiting(philo->table->time_to_sleep);
	print_status(philo, THINKING);
}

void	philo_waiting(unsigned int waiting_time)
{
	usleep(waiting_time * 1000);
}
