/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:58:07 by mohdahma          #+#    #+#             */
/*   Updated: 2025/06/13 18:50:42 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_f);
	pthread_mutex_unlock(philo->right_f);
}
