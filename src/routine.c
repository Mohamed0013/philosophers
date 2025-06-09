/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:17:25 by mohdahma          #+#    #+#             */
/*   Updated: 2025/06/09 17:55:13 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *)philo_p;
	pthread_mutex_lock(&philo->mut_last_meal);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->mut_last_meal);
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->eat_time);
	while (!get_flag(philo->data))
	{
		if (eat(philo) != 0)
			break ;
		if (ft_sleep(philo) != 0)
			break ;
		if (think(philo) != 0)
			break ;
	}
	return (NULL);
}
