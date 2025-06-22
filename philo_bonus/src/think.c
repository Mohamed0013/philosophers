/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:31:38 by mohdahma          #+#    #+#             */
/*   Updated: 2025/06/22 17:31:39 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	think(t_philo *philo)
{
    sem_wait(philo->data->sem_print);
    printf("%zu %d is thinking\n", get_time() - philo->data->start_time, philo->id);
    sem_post(philo->data->sem_print);
    ft_usleep(philo->data->time_to_think);
    return (0);
}
