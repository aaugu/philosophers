/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:26:41 by aaugu             #+#    #+#             */
/*   Updated: 2023/08/30 19:52:57 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include "forks.h"
#include "utils.h"

int	init_forks_mutexes(pthread_mutex_t *fork_locks, int nb_philos)
{
	int	i;

	i = 0;
	while (i < nb_philos)
	{
		if (pthread_mutex_init(&fork_locks[i], NULL) != 0)
			return (msg(STR_ERR_MUTEX, "Fork", ERROR));
		i++;
	}
	return (EXIT_SUCCESS);
}

void	destroy_forks_mutexes(pthread_mutex_t *fork_locks, int nb_philos)
{
	int	i;

	i = 0;
	while (i < nb_philos)
	{
		pthread_mutex_destroy(&fork_locks[i]);
		i++;
	}
}
