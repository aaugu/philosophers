/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:20:36 by aaugu             #+#    #+#             */
/*   Updated: 2023/08/28 10:39:11 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "philosophers.h"
#include "input_checks.h"

int	philosophers(int ac, char **av)
{
	if (is_input_valid(ac, av) == false)
		return (1);
	return (0);
}
