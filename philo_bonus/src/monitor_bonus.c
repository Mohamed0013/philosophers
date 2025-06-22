/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:30:33 by mohdahma          #+#    #+#             */
/*   Updated: 2025/06/22 19:29:15 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

// monitor_bonus.c
void *monitor_self(void *philo_p)
{
    t_philo *philo = (t_philo *)philo_p;
    while (1) {
        if (get_time() - get_last_eat_time(philo) > philo->data->time_to_die
            && get_philo_state(philo) != EATING) {
            sem_wait(philo->data->sem_print);
            printf("%zu %d died\n", get_time() - philo->data->start_time, philo->id);
            exit(1);
        }
        usleep(1000);
    }
    return NULL;
}


bool get_keep_iter(t_data *data)
{
    bool keep_iter;

    if (!data->sem_iter) // Validate semaphore
    {
        fprintf(stderr, "Error: Semaphore not initialized\n");
        return false;
    }

    sem_wait(data->sem_iter);
    keep_iter = data->keep;
    sem_post(data->sem_iter);
    return keep_iter;
}

size_t	get_time_to_die(t_data *data)
{
    size_t	time_to_die;

    sem_wait(data->sem_iter);
    time_to_die = data->time_to_die;
    sem_post(data->sem_iter);
    return (time_to_die);
}

size_t	get_last_eat_time(t_philo *philo)
{
    size_t	last_eat_time;

    sem_wait(&philo->mut_last_meal);
    last_eat_time = philo->last_eat_time;
    sem_post(&philo->mut_last_meal);
    return (last_eat_time);
}

t_state	get_philo_state(t_philo *philo)
{
    t_state	state;

    sem_wait(&philo->mut_state);
    state = philo->state;
    sem_post(&philo->mut_state);
    return (state);
}

bool	philo_died(t_philo *philo)
{
	t_data		*data;

    data = philo->data;
    if (get_time() - get_last_eat_time(philo) > get_time_to_die(data)
        && get_philo_state(philo) != EATING)
    {
        sem_wait(data->sem_print);
        printf("%zu %d died\n", get_time() - data->start_time, philo->id);
        sem_post(data->sem_print);
        return (true);
    }
    return (false);
}

void	*monitoring(void *data_p)
{
	int		i;
	t_data	*data;
	t_philo	*philos;

	data = (t_data *)data_p;
	philos = data->philos;
	i = -1;
	while (++i < data->nb_philos && get_keep_iter(data))
	{
		if (philo_died(&philos[i]))
		{
            sem_wait(data->sem_print);
            printf("%zu %d died\n", get_time() - data->start_time, philos[i].id);
            data->keep = false;
            sem_post(data->sem_dead);
            sem_post(data->sem_full);
            sem_post(data->sem_forks);
            sem_post(data->sem_print);
			break ;
		}
		if (i == data->nb_philos - 1)
			i = -1;
		ft_usleep(500);
	}
	return (NULL);
}