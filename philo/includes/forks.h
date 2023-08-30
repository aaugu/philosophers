/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:56:58 by aaugu             #+#    #+#             */
/*   Updated: 2023/08/30 19:53:04 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORKS_H
# define FORKS_H

int		init_forks_mutexes(pthread_mutex_t *fork_locks, int nb_philos);
void	destroy_forks_mutexes(pthread_mutex_t *forks, int nb_philos);

#endif
