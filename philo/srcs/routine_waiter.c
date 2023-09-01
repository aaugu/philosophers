/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_waiter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:26:25 by aaugu             #+#    #+#             */
/*   Updated: 2023/09/01 11:17:57 by aaugu            ###   ########.fr       */
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
	while (end_of_dinner(table) == false)
	{
		if (philo_died(table) == true || philos_ate_enough(table) == true)
		{
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
		last_meal = table->philos[i].last_meal;
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

	if (table->must_eat < 0)
		return (false);
	i = 0;
	while (i < table->nb_philos)
	{
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
