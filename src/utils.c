/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:59:17 by mohdahma          #+#    #+#             */
/*   Updated: 2025/06/09 17:24:34 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	handle_1_philo(t_philo *philo)
{
	take_left_fork(philo);
	ft_usleep(get_time_to_die(philo->data));
	pthread_mutex_lock(&philo->data->flag_mut);
	philo->data->flag = 1;
	pthread_mutex_unlock(&philo->data->flag_mut);
	pthread_mutex_unlock(philo->left_f);
	return (1);
}

void	free_data(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = data->nb_philos;
	i = -1;
	while (++i < nb_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].mut_state);
		pthread_mutex_destroy(&data->philos[i].nb_meals_eaten);
		pthread_mutex_destroy(&data->philos[i].mut_last_meal);
	}
	pthread_mutex_destroy(&data->mut_die);
	pthread_mutex_destroy(&data->mut_meal);
	pthread_mutex_destroy(&data->mut_sleep);
	pthread_mutex_destroy(&data->mut_write);
	pthread_mutex_destroy(&data->mut_keep_iter);
	pthread_mutex_destroy(&data->mut_start_time);
	free(data->philo_thrd);
	free(data->philos);
	free(data->forks);
}

void	print_msg(t_data *data, int id, char *msg)
{
	size_t	time;

	time = get_time() - get_start_time(data);
	pthread_mutex_lock(&data->mut_write);
	if (get_keep_iter(data))
		printf("%lu %d %s\n", time, id, msg);
	pthread_mutex_unlock(&data->mut_write);
}
