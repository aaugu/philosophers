/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:51:15 by aaugu             #+#    #+#             */
/*   Updated: 2023/09/04 13:54:01 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include "philosophers_dining.h"
#include "routines.h"
#include "utils.h"

bool	dinner_finished(t_table *table)
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

	pthread_mutex_lock(&philo->table->stop_lock);
	if (philo->table->stop == true)
	{
		pthread_mutex_unlock(&philo->table->stop_lock);
		return ;
	}
	pthread_mutex_unlock(&philo->table->stop_lock);
	now = get_time_in_ms() - philo->table->start_time;
	pthread_mutex_lock(&philo->table->print_lock);
	if (status == FORK)
		printf("\e[1;36m%u %d has taken a fork\n\e[0m", now, philo->id + 1);
	else if (status == EATING)
		printf("\e[1;32m%u %d is eating\n\e[0m", now, philo->id + 1);
	else if (status == SLEEPING)
		printf("\e[1;33m%u %d is sleeping\n\e[0m", now, philo->id + 1);
	else if (status == THINKING)
		printf("\e[1;35m%u %d is thinking\n\e[0m", now, philo->id + 1);
	else if (status == DIED)
		printf("\e[1;31m%u %d died\n\e[0m", now, philo->id + 1);
	pthread_mutex_unlock(&philo->table->print_lock);
}
