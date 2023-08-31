/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:10:39 by aaugu             #+#    #+#             */
/*   Updated: 2023/08/31 11:39:14 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_STATUS_H
# define PRINT_STATUS_H

#include "philosophers_dining.h"

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
void	print_status(t_philo *philo, int status);

#endif