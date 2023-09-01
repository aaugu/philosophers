/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:51:15 by aaugu             #+#    #+#             */
/*   Updated: 2023/09/01 12:06:31 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include "philosophers_dining.h"
#include "routines.h"
#include "utils.h"

bool	end_of_dinner(t_table *table)
{
	pthread_mutex_lock(&table->stop_lock);
	if (table->stop == true)
	{
		pthread_mutex_unlock(&table->stop_lock);
		return (true);
	}
	pthread_mutex_unlock(&table->stop_lock);
	return (false);
}

void	print_status(t_philo *philo, int status)
{
	unsigned int	now;

	now = get_time_in_ms() - philo->table->start_time;
	if (end_of_dinner(philo->table) == true)
		return ;
	pthread_mutex_lock(&philo->table->print_lock);
	if (status == FORK)
		printf("%u %d has taken a fork\n", now, philo->id + 1);
	else if (status == EATING)
		printf("%u %d is eating\n", now, philo->id + 1);
	else if (status == SLEEPING)
		printf("%u %d is sleeping\n", now, philo->id + 1);
	else if (status == THINKING)
		printf("%u %d is thinking\n", now, philo->id + 1);
	else if (status == DIED)
		printf("%u %d died\n", now, philo->id + 1);
	pthread_mutex_unlock(&philo->table->print_lock);
}
