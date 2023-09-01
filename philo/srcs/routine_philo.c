/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:53:41 by aaugu             #+#    #+#             */
/*   Updated: 2023/09/01 11:15:48 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
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
	if (philo->id % 2 == 0)
		philo_waiting(philo, 60);
	while (end_of_dinner(philo->table) == false)
		eat_sleep_think(philo);
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
	philo_waiting(philo, philo->table->time_to_die);
	print_status(philo, DIED);
	pthread_mutex_unlock(&philo->table->fork_locks[philo->fork_left]);
	return (NULL);
}

void	eat_sleep_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork_locks[philo->fork_left]);
	print_status(philo, FORK);
	pthread_mutex_unlock(&philo->table->fork_locks[philo->fork_left]);
	pthread_mutex_lock(&philo->table->fork_locks[philo->fork_right]);
	print_status(philo, FORK);
	pthread_mutex_unlock(&philo->table->fork_locks[philo->fork_right]);
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->meal_lock);
	print_status(philo, EATING);
	philo_waiting(philo, philo->table->time_to_eat);
	philo->nb_meals++;
	print_status(philo, SLEEPING);
	philo_waiting(philo, philo->table->time_to_sleep);
	print_status(philo, THINKING);
}

void	philo_waiting(t_philo *philo, unsigned int waiting_time)
{
	unsigned int	limit;

	limit = get_time_in_ms() + waiting_time;
	while (get_time_in_ms() < limit)
	{
		if (end_of_dinner(philo->table) == true)
			break ;
		usleep(1000);
	}
}
