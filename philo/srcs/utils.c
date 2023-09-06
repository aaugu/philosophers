/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:48:17 by aaugu             #+#    #+#             */
/*   Updated: 2023/09/06 19:30:53 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include "utils.h"
#include <sys/time.h>

// atoi() function for unsigned int
unsigned int	ft_atoui(const char *str)
{
	unsigned long int	i;
	int					result;

	i = 0;
	result = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (result > INT_MAX)
		return (-1);
	return (result);
}

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
unsigned int	get_time_in_ms(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	msg(char *str, char *arg, int exit_code)
{
	if (arg)
		printf("%s: %s", arg, str);
	else
		printf("%s", str);
	return (exit_code);
}
