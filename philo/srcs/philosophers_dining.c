/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_dining.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:20:36 by aaugu             #+#    #+#             */
/*   Updated: 2023/08/28 21:55:30 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "philosophers_dining.h"
#include "philos.h"
#include "forks.h"
#include "utils.h"

int		lay_the_table(t_table *table, char **av, int ac);
int		philosophers_having_dinner(t_table *table);
void	clear_the_table(t_table *table);

int	philosophers_dining(int ac, char **av)
{
	t_table	table;

	memset(&table, 0, sizeof(table));
	if (lay_the_table(&table, av, ac) == ERROR)
		return (EXIT_FAILURE);
	if (philosophers_having_dinner(&table) == ERROR)
		return (EXIT_FAILURE);
	clear_the_table(&table);
	return (EXIT_SUCCESS);
}

int	lay_the_table(t_table *table, char **av, int ac)
{
	table->nb_philos = ft_atoui(av[1]);
	table->time_to_die = ft_atoui(av[2]);
	table->time_to_eat = ft_atoui(av[3]);
	table->time_to_sleep = ft_atoui(av[4]);
	table->must_eat = -1;
	if (ac - 1 == 5)
		table->must_eat = ft_atoui(av[5]);
	if (init_philos(table->philos, table->nb_philos) == ERROR)
		return (ERROR);
	if (init_forks_mutexes(table->fork_locks, table->nb_philos) == ERROR)
		return (ERROR);
	return (EXIT_SUCCESS);
}

int	philosophers_having_dinner(t_table *table)
{
	(void) table;
	return (0);
}

void	clear_the_table(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->nb_philos)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
	destroy_forks_mutexes(table->fork_locks, table->nb_philos);
	destroy_philos(table->philos, table->nb_philos);
	pthread_mutex_destroy(&table->prompt_lock);
}
