/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:43:32 by mohdahma          #+#    #+#             */
/*   Updated: 2025/06/22 18:44:07 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int init_semaphores(sem_t **sem, const char *name, int value)
{
    *sem = sem_open(name, O_CREAT | O_EXCL, 0644, value);
    if (*sem == SEM_FAILED)
    {
        perror("sem_open");
        return (MALLOC_ERROR);
    }
    return (0);
}
