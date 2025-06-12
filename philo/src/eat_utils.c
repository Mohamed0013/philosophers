/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:56:53 by mohdahma          #+#    #+#             */
/*   Updated: 2025/06/09 13:48:53 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	drop_left_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_f);
}

void	drop_right_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_f);
}

int	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_f);
	print_msg(philo->data, philo->id, "has taken a fork");
	return (0);
}

int	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_f);
	print_msg(philo->data, philo->id, "has taken a fork");
	return (0);
}

int	take_forks(t_philo *philo)
{
	if (philo->data->nb_philos == 1)
		return (handle_1_philo(philo));
	if (philo->id % 2 == 0)
	{
		if (take_left_fork(philo) != 0)
			return (1);
		if (take_right_fork(philo) != 0)
		{
			pthread_mutex_unlock(philo->left_f);
			return (1);
		}
	}
	else
	{
		if (take_right_fork(philo) != 0)
			return (1);
		if (take_left_fork(philo) != 0)
		{
			pthread_mutex_unlock(philo->right_f);
			return (1);
		}
	}
	return (0);
}
