/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_full_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:30:05 by mohdahma          #+#    #+#             */
/*   Updated: 2025/06/22 17:30:06 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	*all_full_routine(void *data_p)
{
    t_data	*data;
    int		i;

    data = (t_data *)data_p;
    i = 0;
    while (i < data->nb_philos && get_keep_iter(data))
    {
        sem_wait(data->sem_full);
        i++;
    }
    if (i == data->nb_philos)
    {
        sem_wait(data->sem_print);
        printf("All philosophers have eaten enough\n");
        sem_post(data->sem_print);
        data->keep = false;
        sem_post(data->sem_dead);
    }
    return (NULL);
}