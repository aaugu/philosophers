/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_dining.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:54:23 by aaugu             #+#    #+#             */
/*   Updated: 2023/08/28 21:48:15 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_DINING_H
# define PHILOSOPHERS_DINING_H

# include <pthread.h>
# include "philos.h"

# define MAX_PHILOS 200
# define ERROR -1

/******************************************************************************
*                                 Structures                                  *
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
	pthread_mutex_t	fork_locks[MAX_PHILOS];
	pthread_mutex_t	prompt_lock;
}	t_table;

/******************************************************************************
*							    FUNCTIONS									  *
******************************************************************************/
int	philosophers_dining(int ac, char **av);

#endif
