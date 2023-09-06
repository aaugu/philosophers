/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:54:23 by aaugu             #+#    #+#             */
/*   Updated: 2023/09/06 19:26:15 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINES_H
# define ROUTINES_H

# include "philosophers_dining.h"

typedef enum e_status
{
	FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED
}	t_status;

/******************************************************************************
*							    FUNCTIONS									  *
******************************************************************************/
void	*routine(void *data);
void	*checking(void *data);
void	print_status(t_philo *philo, int status, unsigned int now);
bool	dinner_finished(t_table *table);

#endif
