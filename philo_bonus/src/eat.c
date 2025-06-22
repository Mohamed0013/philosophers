/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:30:10 by mohdahma          #+#    #+#             */
/*   Updated: 2025/06/22 19:29:44 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	eat(t_philo *philo)
{
    take_forks(philo);
    philo->state = EATING;
    philo->last_eat_time = get_time();
    ft_usleep(philo->data->eat_time);
    drop_forks(philo);
    return (0);
}


// eat.c
int take_forks(t_philo *philo)
{
    sem_wait(philo->data->sem_forks);
    sem_wait(philo->data->sem_forks);
    return 0;
}
// int	take_left_fork(t_philo *philo)
// {
//     sem_wait(philo->data->sem_forks);
//     philo->left_f = philo->data->sem_forks;
//     return (0);
// }

// int	take_right_fork(t_philo *philo)
// {
//     sem_wait(philo->data->sem_forks);
//     philo->right_f = philo->data->sem_forks;
//     return (0);
// }

void	drop_forks(t_philo *philo)
{
    sem_post(philo->left_f);
    sem_post(philo->right_f);
    philo->left_f = NULL;
    philo->right_f = NULL;
}
