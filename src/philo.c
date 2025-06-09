/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:51:06 by mohdahma          #+#    #+#             */
/*   Updated: 2025/06/08 13:20:29 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_threads(t_data *data)
{
	int	i;
	int	nb_of_philos;

	nb_of_philos = data->nb_philos;
	i = -1;
	data->start_time = get_time();
	while (++i < nb_of_philos)
	{
		if (pthread_create(&data->philo_thrd[i], NULL,
				&routine, &data->philos[i]))
			return (1);
	}
	if (pthread_create(&data->monitor, NULL,
			&monitoring, data))
		return (1);
	if (data->nb_meals > 0
		&& pthread_create(&data->monit_all_full, NULL,
			&all_full_routine, data))
		return (1);
	return (0);
}

int	join_threads(t_data *data)
{
	int	i;

	i = -1;
	if (pthread_join(data->monitor, NULL))
		return (1);
	if (data->nb_meals > 0
		&& pthread_join(data->monit_all_full, NULL))
		return (1);
	while (++i < data->nb_philos)
	{
		if (pthread_join(data->philo_thrd[i], NULL))
			return (1);
	}
	return (0);
}

int	philosophers(int ac, char **av)
{
	t_data	data;

	if (init_data(&data, ac, av) != 0)
		return (MALLOC_ERROR);
	init_philos(&data);
	init_forks(&data);
	init_threads(&data);
	join_threads(&data);
	free_data(&data);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6 || check_input(ac, av) != 0)
	{
		print_instruction();
		return (1);
	}
	if (philosophers(ac, av) != 0)
		return (MALLOC_ERROR);
	return (0);
}
