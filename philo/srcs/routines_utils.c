/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:51:15 by aaugu             #+#    #+#             */
/*   Updated: 2023/09/08 11:17:53 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include "philosophers_dining.h"
#include "routines.h"
#include "utils.h"

bool	dinner_finished(t_table *table)
{
	bool	stop;

	pthread_mutex_lock(&table->stop_lock);
	stop = table->stop;
	pthread_mutex_unlock(&table->stop_lock);
	return (stop);
}

void	print_status(t_philo *philo, int status, unsigned int now)
{
	pthread_mutex_lock(&philo->table->print_lock);
	if (dinner_finished(philo->table))
	{
		pthread_mutex_unlock(&philo->table->print_lock);
		return ;
	}
	now -= philo->table->start_time;
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
