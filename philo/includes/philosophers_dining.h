/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_dining.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:54:23 by aaugu             #+#    #+#             */
/*   Updated: 2023/08/31 10:11:43 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_DINING_H
# define PHILOSOPHERS_DINING_H

# include <pthread.h>
# include <stdbool.h>
# include "philos.h"

# define MAX_PHILOS 200

/******************************************************************************
*                                  Structure                                  *
******************************************************************************/
typedef struct s_table
{
	unsigned int	start_time;
	unsigned int	nb_philos;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	must_eat;
	t_philo			philos[MAX_PHILOS];
	bool			stop;
	pthread_mutex_t	stop_lock;
	pthread_mutex_t	fork_locks[MAX_PHILOS];
	pthread_mutex_t	print_lock;
	pthread_t		waiter;
}	t_table;

/******************************************************************************
*							    FUNCTIONS									  *
******************************************************************************/
int	philosophers_dining(int ac, char **av);

#endif
