/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_waiter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:26:25 by aaugu             #+#    #+#             */
/*   Updated: 2023/09/06 19:37:14 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include "routines.h"
#include "utils.h"
#include "philosophers_dining.h"

bool	end_of_dinner_condition(t_table *table);
bool	philo_died(t_philo *philo);
bool	philo_ate_enough(t_philo *philo);
void	stop_dinner(t_table *table);

void	*checking(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	while (get_time_in_ms() < table->start_time)
		usleep(10);
	if (table->must_eat == 0)
		return (NULL);
	while (true)
	{
		if (end_of_dinner_condition(table) == true)
			return (NULL);
		usleep(10);
	}
	return (NULL);
}

bool	end_of_dinner_condition(t_table *table)
{
	unsigned int	i;
	bool			philos_full;

	i = 0;
	philos_full = true;
	while (i < table->nb_philos)
	{
		if (philo_died(&table->philos[i]))
			return (true);
		if (table->must_eat > 0 && philos_full == true)
		{
			if (philo_ate_enough(&table->philos[i]) == false)
				philos_full = false;
		}
		i++;
	}
	if (philos_full)
	{
		stop_dinner(table);
		return (true);
	}
	return (false);
}

bool	philo_died(t_philo *philo)
{
	unsigned int	now;
	unsigned int	last_meal;

	now = get_time_in_ms();
	pthread_mutex_lock(&philo->meal_lock);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->meal_lock);
	if (now - last_meal >= philo->table->time_to_die)
	{
		pthread_mutex_lock(&philo->meal_lock);
		philo->dead = true;
		pthread_mutex_unlock(&philo->meal_lock);
		print_status(philo, DIED, get_time_in_ms());
		stop_dinner(philo->table);
		return (true);
	}
	return (false);
}

bool	philo_ate_enough(t_philo *philo)
{
	unsigned int	nb_meals;

	pthread_mutex_lock(&philo->meal_lock);
	nb_meals = philo->nb_meals;
	pthread_mutex_unlock(&philo->meal_lock);
	if (nb_meals < (unsigned int)philo->table->must_eat)
		return (false);
	return (true);
}

void	stop_dinner(t_table *table)
{
	pthread_mutex_lock(&table->stop_lock);
	table->stop = true;
	pthread_mutex_unlock(&table->stop_lock);
}
