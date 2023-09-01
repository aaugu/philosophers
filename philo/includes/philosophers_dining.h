/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_dining.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:54:23 by aaugu             #+#    #+#             */
/*   Updated: 2023/09/01 11:46:57 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_DINING_H
# define PHILOSOPHERS_DINING_H

# include <pthread.h>
# include <stdbool.h>

# define MAX_PHILOS 200

/******************************************************************************
*                                  Structure                                  *
******************************************************************************/
typedef struct s_table	t_table;

typedef struct s_philo
{
	unsigned int	id;
	unsigned int	fork_left;
	unsigned int	fork_right;
	unsigned int	nb_meals;
	unsigned int	last_meal;
	pthread_mutex_t	meal_lock;
	t_table			*table;
	pthread_t		thread;
}					t_philo;

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
