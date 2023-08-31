/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:42:00 by aaugu             #+#    #+#             */
/*   Updated: 2023/08/31 10:38:38 by aaugu            ###   ########.fr       */
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

int		init_philos(t_philo *philos, int nb_philos, t_table *table);
void	destroy_philos(t_philo *philos, int nb_philos);

#endif
