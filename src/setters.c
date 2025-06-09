/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:58:54 by mohdahma          #+#    #+#             */
/*   Updated: 2025/06/09 13:51:51 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	set_keep(t_data *data, bool set_to)
{
	pthread_mutex_lock(&data->mut_keep_iter);
	data->keep = set_to;
	pthread_mutex_unlock(&data->mut_keep_iter);
}

void	set_philo_state(t_philo *philo, t_state state)
{
	pthread_mutex_lock(&philo->mut_state);
	if (get_flag(philo->data))
		philo->state = state;
	pthread_mutex_unlock(&philo->mut_state);
}
