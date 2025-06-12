/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:58:58 by mohdahma          #+#    #+#             */
/*   Updated: 2025/06/12 20:14:38 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_state);
	if (get_flag(philo->data) == 0)
		philo->state = SLEEPING;
	pthread_mutex_unlock(&philo->mut_state);
	if (get_flag(philo->data))
		return (1);
	print_msg(philo->data, philo->id, "is sleeping");
	ft_usleep(philo->data);
	return (0);
}
