/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:20:36 by aaugu             #+#    #+#             */
/*   Updated: 2023/08/23 17:38:57 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "checks.h"

int	philosophers(int ac, char **av)
{
	if (input_checks(ac, av) == ERROR)
		return (1);
	return (0);
}
