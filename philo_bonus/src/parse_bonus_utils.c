/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pare_bonus_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:45:56 by mohdahma          #+#    #+#             */
/*   Updated: 2025/06/22 17:46:00 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		if (res > (9223372036854775807 - (str[i] - '0')) / 10)
			return (-sign * (sign == 1));
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void	print_instruction(void)
{
	printf("WRONG INPUT! Usage :\n");
	printf("./philo nb_philos time_to_die\
    time_to_eat time_to_sleep\
    number_of_times_each_philosopher_must_eat\
    (optional argument)\n");
	printf("Example:\n");
	printf("./philo 4 800 200 200 5\n");
}
