/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 12:54:53 by mohdahma          #+#    #+#             */
/*   Updated: 2025/06/22 19:22:29 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	init_data(t_data *data, int ac, char **av)
{
    if (ac != 5)
        return (wrong_input_check(ac, av));
    data->nb_philos = ft_atoi(av[1]);
    data->time_to_die = ft_atoi(av[2]);
    data->eat_time = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);
    data->keep = true;
    data->flag = false;
    return (0);
}

int init_semaphores_all(t_data *data)
{
    if (init_semaphores(&data->sem_forks, SEM_FORKS, data->nb_philos) != 0)
        return (MALLOC_ERROR);
    if (init_semaphores(&data->sem_print, SEM_PRINT, 1) != 0)
        return (MALLOC_ERROR);
    if (init_semaphores(&data->sem_full, SEM_FULL, 0) != 0)
        return (MALLOC_ERROR);
    if (init_semaphores(&data->sem_dead, SEM_DEAD, 0) != 0)
        return (MALLOC_ERROR);
    if (init_semaphores(&data->sem_iter, SEM_ITER, 1) != 0)
        return (MALLOC_ERROR);
    return (0);
}

int	init_philos(t_data *data)
{
    int	i;

    data->philos = malloc(sizeof(t_philo) * data->nb_philos);
    if (!data->philos)
        return (MALLOC_ERROR);
    i = 0;
    while (i < data->nb_philos)
    {
        data->philos[i].id = i + 1;
        data->philos[i].data = data;
        data->philos[i].state = THINKING;
        data->philos[i].nb_meals_had = 0;
        data->philos[i].last_eat_time = get_time();
        i++;
    }
    return (0);
}

int	init_forks(t_data *data)
{
    return (init_semaphores(&data->sem_forks, SEM_FORKS, data->nb_philos));
}
