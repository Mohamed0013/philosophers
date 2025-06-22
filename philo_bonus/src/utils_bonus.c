/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:32:05 by mohdahma          #+#    #+#             */
/*   Updated: 2025/06/22 19:30:29 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void ft_usleep(size_t time)
{
    size_t start = get_time();
    while (get_time() - start < time)
        usleep(500);
}

size_t	get_time(void)
{
    struct timeval	tv;

    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void free_data(t_data *data)
{
    if (data->sem_forks)
    {
        sem_unlink(SEM_FORKS);
        sem_close(data->sem_forks);
    }
    if (data->sem_print)
    {
        sem_unlink(SEM_PRINT);
        sem_close(data->sem_print);
    }
    if (data->sem_full)
    {
        sem_unlink(SEM_FULL);
        sem_close(data->sem_full);
    }
    if (data->sem_dead)
    {
        sem_unlink(SEM_DEAD);
        sem_close(data->sem_dead);
    }
    free(data->philos);
    free(data->philo_thrd);
}

void	free_philos(t_data *data)
{
    int	i;

    i = 0;
    while (i < data->nb_philos)
    {
        if (data->philos[i].left_f)
            sem_close(data->philos[i].left_f);
        if (data->philos[i].right_f)
            sem_close(data->philos[i].right_f);
        i++;
    }
}
