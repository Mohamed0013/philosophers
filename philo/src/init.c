/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:15:26 by mohdahma          #+#    #+#             */
/*   Updated: 2025/06/09 14:01:41 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_forks(t_data *data)
{
	int		i;
	t_philo	*philos;

	philos = data->philos;
	i = -1;
	while (++i < data->nb_philos)
		pthread_mutex_init(&data->forks[i], NULL);
	i = 0;
	philos[0].left_f = &data->forks[0];
	philos[0].right_f = &data->forks[data->nb_philos - 1];
	while (++i < data->nb_philos)
	{
		philos[i].left_f = &data->forks[i];
		philos[i].right_f = &data->forks[i - 1];
	}
	return (0);
}

int	init_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = data->philos;
	while (i < data->nb_philos)
	{
		philos[i].data = data;
		philos[i].id = i + 1;
		philos[i].nb_meals_had = 0;
		philos[i].state = INACT;
		pthread_mutex_init(&philos[i].mut_state, NULL);
		pthread_mutex_init(&philos[i].nb_meals_eaten, NULL);
		pthread_mutex_init(&philos[i].mut_last_meal, NULL);
		i++;
	}
	return (0);
}

int	malloc_data(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->nb_philos);
	if (data->philos == NULL)
		return (MALLOC_ERROR);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (data->forks == NULL)
		return (free(data->philos), MALLOC_ERROR);
	data->philo_thrd = malloc(sizeof(pthread_t) * data->nb_philos);
	if (data->philo_thrd == NULL)
		return (free(data->philos), free(data->forks), MALLOC_ERROR);
	return (0);
}

int	init_data(t_data *data, int ac, char **av)
{
	data->nb_full_philos = 0;
	data->keep = true;
	data->nb_philos = ft_atoi(av[1]);
	data->time_to_die = (size_t)ft_atoi(av[2]);
	data->eat_time = (size_t)ft_atoi(av[3]);
	data->sleep_time = (size_t)ft_atoi(av[4]);
	data->nb_meals = -1;
	data->flag = 0;
	if (ac == 6)
		data->nb_meals = ft_atoi(av[5]);
	pthread_mutex_init(&data->mut_meal, NULL);
	pthread_mutex_init(&data->mut_sleep, NULL);
	pthread_mutex_init(&data->mut_die, NULL);
	pthread_mutex_init(&data->mut_write, NULL);
	pthread_mutex_init(&data->mut_keep_iter, NULL);
	pthread_mutex_init(&data->mut_start_time, NULL);
	pthread_mutex_init(&data->flag_mut, NULL);
	return (malloc_data(data));
}
