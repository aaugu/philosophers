/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_dining.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:20:36 by aaugu             #+#    #+#             */
/*   Updated: 2023/08/31 15:13:28 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "philosophers_dining.h"
#include "routines.h"
#include "forks.h"
#include "philos.h"
#include "utils.h"
#include <unistd.h>

int		lay_the_table(t_table *table, char **av, int ac);
int		philosophers_having_dinner(t_table *table);
int		destroy_mutexes(t_table *table, int exit_code);
void	clear_the_table(t_table *table);

int	philosophers_dining(int ac, char **av)
{
	t_table	table;

	if (ac == 6 && av[5] == 0)
		return (EXIT_SUCCESS);
	if (lay_the_table(&table, av, ac) == ERROR)
		return (destroy_mutexes(&table, EXIT_FAILURE));
	if (philosophers_having_dinner(&table) == ERROR)
		return (destroy_mutexes(&table, EXIT_FAILURE));
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
	table->stop = false;
	if (ac - 1 == 6)
		table->must_eat = ft_atoui(av[5]);
	if (init_philos(table->philos, table->nb_philos, table) == ERROR)
		return (ERROR);
	if (init_forks_mutexes(table->fork_locks, table->nb_philos) == ERROR)
		return (ERROR);
	if (pthread_mutex_init(&table->print_lock, NULL) != 0)
		return (msg(STR_ERR_MUTEX, "Print lock", ERROR));
	if (pthread_mutex_init(&table->stop_lock, NULL) != 0)
		return (msg(STR_ERR_MUTEX, "Stop lock", ERROR));
	return (EXIT_SUCCESS);
}

int	philosophers_having_dinner(t_table *table)
{
	unsigned int	i;

	table->start_time = get_time_in_ms() + (table->nb_philos * 10);
	i = 0;
	while (i < table->nb_philos)
	{
		if (pthread_create(&table->philos[i].thread, NULL, &routine,
				(void *)&table->philos[i]) != 0)
			return (msg(STR_ERR_THREAD, "Philo", ERROR));
		i++;
	}
	if (table->nb_philos == 1)
		return (EXIT_SUCCESS);
	if (pthread_create(&table->waiter, NULL, &checking, (void *)table) != 0)
		return (msg(STR_ERR_THREAD, "Waiter", ERROR));
	return (EXIT_SUCCESS);
}

int	destroy_mutexes(t_table *table, int exit_code)
{
	destroy_forks_mutexes(table->fork_locks, table->nb_philos);
	destroy_philos(table->philos, table->nb_philos);
	pthread_mutex_destroy(&table->print_lock);
	pthread_mutex_destroy(&table->stop_lock);
	return (exit_code);
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
	if (table->nb_philos > 1)
		pthread_join(table->waiter, NULL);
	destroy_mutexes(table, EXIT_SUCCESS);
}
