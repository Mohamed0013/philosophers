/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 12:29:49 by mohdahma          #+#    #+#             */
/*   Updated: 2025/06/22 19:33:23 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"
#include <signal.h>

// philo_bonus.c
void parent_cleanup(t_data *data)
{
    int status;
    pid_t pid;

    while ((pid = waitpid(-1, &status, 0)) > 0) {
        if (WIFEXITED(status) && WEXITSTATUS(status) == 1) {
            // Kill other philosophers if one died
            for (int i = 0; i < data->nb_philos; i++) {
                if (data->philos[i].pid != pid)
                    kill(data->philos[i].pid, SIGKILL);
            }
            break;
        }
    }
    free_data(data);
}

// philo_bonus.c (child process)
void child_routine(t_philo *philo)
{
    pthread_t monitor;
    pthread_create(&monitor, NULL, monitor_self, philo);
    routine(philo);
    pthread_join(monitor, NULL);
    exit(0);
}

void start_philosophers(t_data *data)
{
    int i;

    // Start monitoring threads before forking philosophers
    pthread_create(&data->monitor, NULL, monitoring, data);
    pthread_create(&data->monit_all_full, NULL, all_full_routine, data);

    i = 0;
    data->start_time = get_time();
    while (i < data->nb_philos)
    {
        pid_t pid = fork();
        if (pid == 0)
        {
            routine(&data->philos[i]);
            exit(0);
        }
        else if (pid > 0)
        {
            data->philos[i].pid = pid;
        }
        else
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        i++;
    }

    // Wait for monitoring threads to finish
    pthread_join(data->monitor, NULL);
    pthread_join(data->monit_all_full, NULL);

    // Wait for all child processes to finish
    for (i = 0; i < data->nb_philos; i++)
        waitpid(data->philos[i].pid, NULL, 0);
}

int main(int ac, char **av)
{
    t_data data;
    int ret;

    // Initialize data
    ret = init_data(&data, ac, av);
    if (ret != 0)
    {
        fprintf(stderr, "Error: Invalid input\n");
        return (ret);
    }

    // Initialize philosophers
    ret = init_philos(&data);
    if (ret != 0)
    {
        fprintf(stderr, "Error: Failed to initialize philosophers\n");
        return (ret);
    }

    // Initialize semaphores
    ret = init_semaphores(&data.sem_forks, SEM_FORKS, data.nb_philos);
    if (ret != 0)
    {
        fprintf(stderr, "Error: Failed to initialize semaphores\n");
        free_data(&data);
        return (ret);
    }

    // Start philosopher processes
    start_philosophers(&data);

    // Wait for all child processes to finish
    // for (int i = 0; i < data.nb_philos; i++)
    //     waitpid(data.philos[i].pid, NULL, 0);

    // Cleanup
    free_data(&data);

    return (0);
}