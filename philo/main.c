/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:08:44 by aaugu             #+#    #+#             */
/*   Updated: 2023/07/24 14:03:09 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char ** av)
{
	if (ac == 5)
		simple_philo(av);
	else if (ac == 6)
		complex_philo(av);
	else
	{
		if (ac < 5)
			printf("Error: Not enough arguments.");
		else
			printf("Error: Too much arguments.");
		return (1);
	}
	return (0);
}
