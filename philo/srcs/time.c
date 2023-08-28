/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:10:59 by aaugu             #+#    #+#             */
/*   Updated: 2023/08/28 16:15:12 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>

/*
int gettimeofday(struct timeval *tv, struct timezone *tz);
	* Gives the number of seconds and microseconds since the Epoch.
	* Argument tv stands for :
		struct timeval {
			time_t      tv_sec;     # seconds
			suseconds_t tv_usec;    # microseconds
		};
 	* The use of the timezone structure is obsolete; the tz argument should
		normally be specified as NULL.
*/

/* Converts gettimeofday in ms */
int	get_time_in_ms(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
