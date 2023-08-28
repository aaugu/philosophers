/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:15:44 by aaugu             #+#    #+#             */
/*   Updated: 2023/08/23 17:49:58 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_utils.h"

int		ft_intsize(int n);
void	ft_convertint(int n, int size, char *str);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_intsize(n);
	if (n < 0)
		size++;
	str = malloc(sizeof(*str) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	ft_convertint(n, size, str);
	return (str);
}

int	ft_intsize(int n)
{
	int	size;

	size = 1;
	n /= 10;
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

void	ft_convertint(int n, int size, char *str)
{
	while (n > 0 && size > 0)
	{
		str[size-- - 1] = n % 10 + '0';
		n /= 10;
	}
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
