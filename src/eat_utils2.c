/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:58:07 by mohdahma          #+#    #+#             */
/*   Updated: 2025/04/30 12:58:08 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_f);
	pthread_mutex_unlock(philo->right_f);
}

void	update_last_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_last_meal);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->mut_last_meal);
}

void	update_nb_meals_had(t_philo *philo)
{
	pthread_mutex_lock(&philo->nb_meals_eaten);
	philo->nb_meals_had++;
	pthread_mutex_unlock(&philo->nb_meals_eaten);
}

void	sleep_for_eating(t_philo *philo)
{
	ft_usleep(get_eat_time(philo->data));
}
