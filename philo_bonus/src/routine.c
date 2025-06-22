/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:31:11 by mohdahma          #+#    #+#             */
/*   Updated: 2025/06/22 17:39:22 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	*routine(void *philo_p)
{
    t_philo	*philo;

    philo = (t_philo *)philo_p;
    while (philo->data->keep)
    {
        if (eat(philo) != 0)
            return (NULL);
        if (ft_sleep(philo) != 0)
            return (NULL);
        if (think(philo) != 0)
            return (NULL);
    }
    return (NULL);
}
