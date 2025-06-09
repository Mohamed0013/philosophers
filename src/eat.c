/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:20:11 by mohdahma          #+#    #+#             */
/*   Updated: 2025/06/09 16:53:29 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	eat(t_philo *philo)
{
	if (take_forks(philo) != 0)
		return (1);
	pthread_mutex_lock(&philo->mut_state);
	if (get_flag(philo->data) == 0)
		philo->state = EATING;
	pthread_mutex_unlock(&philo->mut_state);
	print_msg(philo->data, philo->id, "is eating");
	pthread_mutex_lock(&philo->mut_last_meal);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->mut_last_meal);
	ft_usleep(get_eat_time(philo->data));
	pthread_mutex_lock(&philo->nb_meals_eaten);
	philo->nb_meals_had++;
	pthread_mutex_unlock(&philo->nb_meals_eaten);
	pthread_mutex_unlock(philo->left_f);
	pthread_mutex_unlock(philo->right_f);
	return (0);
}
