/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:59:03 by aaugu             #+#    #+#             */
/*   Updated: 2023/08/31 14:24:23 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include "utils.h"
#include "print_status.h"
#include "philosophers_dining.h"

void	print_status(t_philo *philo, int status)
{
	unsigned int	now;

	now = get_time_in_ms() - philo->table->start_time;
	pthread_mutex_lock(&philo->table->print_lock);
	if (status == FORK)
		printf("%u %d has taken a fork\n", now, philo->id + 1);
	if (status == EATING)
		printf("%u %d is eating\n", now, philo->id + 1);
	if (status == SLEEPING)
		printf("%u %d is sleeping\n", now, philo->id + 1);
	if (status == THINKING)
		printf("%u %d is thinking\n", now, philo->id + 1);
	if (status == DIED)
		printf("%u %d died\n", now, philo->id + 1);
	pthread_mutex_unlock(&philo->table->print_lock);
}
