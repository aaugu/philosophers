/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_waiter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:26:25 by aaugu             #+#    #+#             */
/*   Updated: 2023/09/01 14:48:33 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include "routines.h"
#include "utils.h"
#include "philosophers_dining.h"

bool	philo_died(t_table *table);
bool	philos_ate_enough(t_table *table);
void	stop_dinner(t_table *table);

void	*checking(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	while (get_time_in_ms() < table->start_time)
		continue ;
	while (end_of_dinner(table) == false)
	{
		if (philo_died(table) == true)
		{
			stop_dinner(table);
			return (NULL);
		}
		if (table->must_eat < 0)
			continue ;
		else if (philos_ate_enough(table) == true)
		{
			printf("ici");
			stop_dinner(table);
			return (NULL);
		}
	}
	return (NULL);
}

bool	philo_died(t_table *table)
{
	unsigned int	i;
	unsigned int	last_meal;
	unsigned int	now;

	i = 0;
	now = get_time_in_ms();
	while (i < table->nb_philos)
	{
		pthread_mutex_lock(&table->philos[i].meal_lock);
		last_meal = table->philos[i].last_meal;
		pthread_mutex_unlock(&table->philos[i].meal_lock);
		if (now - last_meal >= table->time_to_die)
		{
			print_status(&table->philos[i], DIED);
			return (true);
		}
		i++;
	}
	return (false);
}

bool	philos_ate_enough(t_table *table)
{
	unsigned int	i;
	unsigned int	nb_meals;

	i = 0;
	while (i < table->nb_philos)
	{
		pthread_mutex_lock(&table->philos[i].meal_lock);
		nb_meals = table->philos[i].nb_meals;
		pthread_mutex_unlock(&table->philos[i].meal_lock);
		if (table->philos[i].nb_meals < table->must_eat)
			return (false);
	}
	return (true);
}

void	stop_dinner(t_table *table)
{
	pthread_mutex_lock(&table->stop_lock);
	table->stop = true;
	pthread_mutex_unlock(&table->stop_lock);
}
