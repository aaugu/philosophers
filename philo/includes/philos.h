/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:42:00 by aaugu             #+#    #+#             */
/*   Updated: 2023/08/31 10:20:22 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include <pthread.h>
# include "philosophers_dining.h"

# define ERROR -1

/******************************************************************************
*                                  Structure                                  *
******************************************************************************/
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

int		init_philos(t_philo *philos, int nb_philos, t_table *table);
void	destroy_philos(t_philo *philos, int nb_philos);

#endif
