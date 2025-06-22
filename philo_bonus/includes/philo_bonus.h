/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 12:31:12 by mohdahma          #+#    #+#             */
/*   Updated: 2025/06/22 19:31:38 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdbool.h>
# include <semaphore.h>
# include <pthread.h>
#include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>

# define MALLOC_ERROR 2
# define SEM_FORKS "sem_forks"
# define SEM_PRINT "sem_print"
# define SEM_FULL "sem_full"
# define SEM_DEAD "sem_dead"
# define SEM_MEALS "sem_meals"
# define SEM_ITER "sem_iter"
# define SEM_DEAD_PHILO "sem_dead_philo"
# define SEM_FORKS_COUNT "sem_forks_count"
# define SEM_FORKS_COUNT_MAX 1
# define SEM_FORKS_COUNT_MIN 0
# define SEM_FORKS_MAX 200
# define SEM_FORKS_MIN 0
# define SEM_PRINT_MAX 1
# define SEM_PRINT_MIN 0
# define SEM_FULL_MAX 1
# define SEM_FULL_MIN 0
# define SEM_DEAD_MAX 1
# define SEM_DEAD_MIN 0
# define SEM_MEALS_MAX 1
# define SEM_MEALS_MIN 0
# define SEM_ITER_MAX 1
# define SEM_ITER_MIN 0
# define SEM_DEAD_PHILO_MAX 1
# define SEM_DEAD_PHILO_MIN 0

typedef enum e_philo_state
{
    INACT = 0,
    EATING = 1,
    SLEEPING = 2,
    THINKING = 3,
    FULL = 4
}				t_state;

typedef struct  s_philo
{
    int             id;
    int             nb_meals_had;
    struct s_data   *data;
    t_state         state;
    sem_t           *left_f;
    sem_t           *right_f;
    sem_t           mut_state;
    sem_t           nb_meals_eaten;
    sem_t           mut_last_meal;
    size_t          last_eat_time;
    pid_t           pid; // Add this field to store the process ID
}                      t_philo;

typedef struct s_data
{
    int				nb_philos;
    int				nb_meals;
    int				nb_full_philos;
    bool			keep;
    bool			flag;
    size_t			eat_time;
    size_t			time_to_die;
    size_t			time_to_sleep;
    size_t			start_time;
    size_t          time_to_think;
    sem_t			*sem_forks;
    sem_t			*sem_print;
    sem_t			*sem_full;
    sem_t			*sem_dead;
    sem_t			*sem_meals;
    sem_t			*sem_iter;
    sem_t			*sem_dead_philo;
    sem_t			*sem_forks_count;
    pthread_t		monitor;
    pthread_t		monit_all_full;
    pthread_t		*philo_thrd;
    t_philo			*philos;
}				t_data;

// shared_memory.h
typedef struct s_shared {
    int death_flag;
    sem_t *sem_forks;
    sem_t *sem_print;
    // Add other needed semaphores
} t_shared;

// routine.c
void		*routine(void *philo_p);
bool		philo_died(t_philo *philo);

// parse.c
int			check_input(int ac, char **av);
int			wrong_input_check(int ac, char **av);
void		print_instruction(void);

// utils.c
void		ft_usleep(size_t time);
size_t		get_time(void);
void		free_data(t_data *data);
void		free_philos(t_data *data);

// init.c
int			init_data(t_data *data, int ac, char **av);
int			init_philos(t_data *data);
int			init_forks(t_data *data);
// int			init_semaphores(t_data *data);

// semaphores.c
void        start_philosophers(t_data *data);

// semaphore_utils.c
int     init_semaphores(sem_t **sem, const char *name, int value);

// parse_utils.c
int			ft_atoi(const char *str);
int			ft_isspace(char c);
int			ft_isdigit(char c);

// eat.c
int			eat(t_philo *philo);
int			take_forks(t_philo *philo);
int			take_right_fork(t_philo *philo);
int			take_left_fork(t_philo *philo);
void		drop_forks(t_philo *philo);

// sleep.c
int			ft_sleep(t_philo *philo);

// think.c
int			think(t_philo *philo);

// monitoring.c
void		*all_full_routine(void *data_p);
void		*monitoring(void *data_p);

// getters.c
size_t		get_time_to_die(t_data *data);
size_t		get_eat_time(t_data *data);
size_t		get_sleep_time(t_data *data);
bool		get_keep_iter(t_data *data);
size_t		get_start_time(t_data *data);
t_state		get_philo_state(t_philo *philo);
int			get_nb_meals_philo_had(t_philo *philo);
size_t		get_last_eat_time(t_philo *philo);
int			get_flag(t_data *data);

// setters.c
void		set_keep(t_data *data, bool set_to);
void		set_philo_state(t_philo *philo, t_state state);


bool	get_keep_iter(t_data *data);
bool	philo_died(t_philo *philo);
int init_semaphores_all(t_data *data);
void *monitor_self(void *philo_p);

#endif