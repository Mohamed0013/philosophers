/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:58:58 by mohdahma          #+#    #+#             */
/*   Updated: 2025/06/26 18:48:57 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_state);
	if (get_flag(philo->data) == 0)
		philo->state = SLEEPING;
	pthread_mutex_unlock(&philo->mut_state);
	pthread_mutex_lock(&philo->data->mut_write);
	print_msg(philo->data, philo->id, "is sleeping");
	pthread_mutex_unlock(&philo->data->mut_write);
	ft_usleep(philo->data->sleep_time);
	return (0);
}
