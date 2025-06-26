/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:59:02 by mohdahma          #+#    #+#             */
/*   Updated: 2025/06/26 19:34:03 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	think(t_philo *philo)
{
	size_t	time_since_last_meal;
	size_t	time_to_think;

	time_since_last_meal = get_time() - philo->last_eat_time;
	if (time_since_last_meal >= philo->data->time_to_die)
		return (1);
	if (get_flag(philo->data) == 0)
		set_philo_state(philo, THINKING);
	else
		return (1);
	pthread_mutex_lock(&philo->data->mut_write);
	print_msg(philo->data, philo->id, "is thinking");
	pthread_mutex_unlock(&philo->data->mut_write);
	time_to_think = philo->data->time_to_die - time_since_last_meal;
	if (time_to_think > 0 && philo->data->nb_philos % 2 != 0)
		ft_usleep(time_to_think / 2);
	return (0);
}
