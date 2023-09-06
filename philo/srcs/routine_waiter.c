/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_waiter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:26:25 by aaugu             #+#    #+#             */
/*   Updated: 2023/09/06 14:26:21 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include "routines.h"
#include "utils.h"
#include "philosophers_dining.h"

void	check_on_dinner(t_table *table);
bool	philo_died(t_philo *philo, unsigned int now, unsigned int last_meal);
bool	philo_ate_enough(int must_eat, unsigned int nb_meals);
void	stop_dinner(t_table *table);

void	*checking(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	while (get_time_in_ms() < table->start_time)
		continue ;
	while (true)
	{
		check_on_dinner(table);
		if (table->philo_dead || table->philos_full == table->nb_philos)
		{
			stop_dinner(table);
			return (NULL);
		}
	}
	return (NULL);
}

void	check_on_dinner(t_table *table)
{
	unsigned int	i;
	unsigned int	nb_meals;
	unsigned int	last_meal;
	unsigned int	now;

	i = 0;
	table->philos_full = 0;
	while (i < table->nb_philos)
	{
		pthread_mutex_lock(&table->philos[i].meal_lock);
		nb_meals = table->philos[i].nb_meals;
		last_meal = table->philos[i].last_meal;
		pthread_mutex_unlock(&table->philos[i].meal_lock);
		now = get_time_in_ms();
		if (philo_died(&table->philos[i], now, last_meal))
			return ;
		if (table->must_eat > 0)
		{
			if (nb_meals >= (unsigned int)table->must_eat)
				table->philos_full++;
		}
		i++;
	}
}

bool	philo_died(t_philo *philo, unsigned int now, unsigned int last_meal)
{
	if (now - last_meal >= philo->table->time_to_die)
	{
		philo->table->philo_dead = true;
		print_status(philo, DIED);
		return (true);
	}
	return (false);
}

bool	philo_ate_enough(int must_eat, unsigned int nb_meals)
{
	if ((int)nb_meals < must_eat)
		return (false);
	return (true);
}

void	stop_dinner(t_table *table)
{
	pthread_mutex_lock(&table->stop_lock);
	table->stop = true;
	pthread_mutex_unlock(&table->stop_lock);
}
