/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:59:02 by mohdahma          #+#    #+#             */
/*   Updated: 2025/06/09 16:52:58 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	think(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_state);
	if (get_flag(philo->data) == 0)
		philo->state = THINKING;
	pthread_mutex_unlock(&philo->mut_state);
	if (get_flag(philo->data))
		return (1);
	print_msg(philo->data, philo->id, "is thinking");
	return (0);
}
