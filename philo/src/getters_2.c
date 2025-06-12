/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:58:15 by mohdahma          #+#    #+#             */
/*   Updated: 2025/06/09 17:58:09 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

size_t	get_time_to_die(t_data *data)
{
	size_t	time_to_die;

	pthread_mutex_lock(&data->mut_die);
	time_to_die = data->time_to_die;
	pthread_mutex_unlock(&data->mut_die);
	return (time_to_die);
}

size_t	get_sleep_time(t_data *data)
{
	size_t	sleep_time;

	pthread_mutex_lock(&data->mut_sleep);
	sleep_time = data->sleep_time;
	pthread_mutex_unlock(&data->mut_sleep);
	return (sleep_time);
}

size_t	get_eat_time(t_data *data)
{
	size_t	eat_time;

	pthread_mutex_lock(&data->mut_meal);
	eat_time = data->eat_time;
	pthread_mutex_unlock(&data->mut_meal);
	return (eat_time);
}

size_t	get_last_eat_time(t_philo *philo)
{
	size_t	last_eat_time;

	pthread_mutex_lock(&philo->mut_last_meal);
	last_eat_time = philo->last_eat_time;
	pthread_mutex_unlock(&philo->mut_last_meal);
	return (last_eat_time);
}

int	get_flag(t_data *data)
{
	int	flag;

	pthread_mutex_lock(&data->flag_mut);
	flag = data->flag;
	pthread_mutex_unlock(&data->flag_mut);
	return (flag);
}
