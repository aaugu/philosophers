/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:48:37 by aaugu             #+#    #+#             */
/*   Updated: 2023/08/30 19:47:13 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define ERROR -1
# define STR_ERR_MALLOC "Error: malloc failed()."
# define STR_ERR_MUTEX "Error: could not create mutex."
# define STR_ERR_THREAD "Error: could not create thread."

unsigned int	ft_atoui(const char *str);
int				get_time_in_ms(void);
int				msg(char *str, char *arg, int exit_code);

#endif
