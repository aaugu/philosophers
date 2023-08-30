/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:42:00 by aaugu             #+#    #+#             */
/*   Updated: 2023/08/29 16:03:54 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include <pthread.h>

# define ERROR -1
/******************************************************************************
*                                 Structures                                  *
******************************************************************************/
typedef struct s_philo
{
	unsigned int	id;
	unsigned int	fork_left;
	unsigned int	fork_right;
	unsigned int	nb_meals;
	pthread_t		thread;
	pthread_mutex_t	mutex;
}					t_philo;

int		init_philos(t_philo *philos, int nb_philos);
void	destroy_philos(t_philo *philos, int nb_philos);

#endif
