/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:38:07 by mohdahma          #+#    #+#             */
/*   Updated: 2025/06/09 17:15:38 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	is_philo_full(t_data *data, t_philo *philo)
{
	bool	result;

	result = false;
	if (get_nb_meals_philo_had(philo) >= data->nb_meals)
		result = true;
	return (result);
}

bool	philo_died(t_philo *philo)
{
	t_data		*data;

	data = philo->data;
	if (get_time() - get_last_eat_time(philo) > get_time_to_die(data)
		&& get_philo_state(philo) != EATING)
	{
		pthread_mutex_lock(&data->flag_mut);
		philo->data->flag = 1;
		pthread_mutex_unlock(&data->flag_mut);
		return (true);
	}
	return (false);
}

void	*all_full_routine(void *data_p)
{
	t_data	*data;
	int		i;

	data = (t_data *)data_p;
	i = -1;
	while (++i < data->nb_philos && get_keep_iter(data))
	{
		usleep(1000);
		if (is_philo_full(data, &data->philos[i]) == false)
			i = -1;
	}
	if (get_keep_iter(data) == true)
	{
		set_keep(data, false);
		pthread_mutex_lock(&data->flag_mut);
		data->flag = 1;
		pthread_mutex_unlock(&data->flag_mut);
	}
	return (NULL);
}

void	*monitoring(void *data_p)
{
	int		i;
	t_data	*data;
	t_philo	*philos;

	data = (t_data *)data_p;
	philos = data->philos;
	i = -1;
	while (++i < data->nb_philos && get_keep_iter(data))
	{
		if (philo_died(&philos[i]) && get_keep_iter(data))
		{
			print_msg(data, philos[i].id, "died");
			set_keep(data, false);
			pthread_mutex_lock(&data->flag_mut);
			data->flag = 1;
			pthread_mutex_unlock(&data->flag_mut);
			break ;
		}
		if (i == data->nb_philos - 1)
			i = -1;
	}
	return (NULL);
}
