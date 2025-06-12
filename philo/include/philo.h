/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:23:43 by mohdahma          #+#    #+#             */
/*   Updated: 2025/06/12 20:15:01 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdbool.h>

# define MALLOC_ERROR 2

typedef enum e_philo_state
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
	// DEAD = 3,
	FULL = 4,
	INACT = 5
}				t_state;

typedef struct s_philo
{
	int				id;
	int				nb_meals_had;
	struct s_data	*data;
	t_state			state;
	pthread_mutex_t	*left_f;
	pthread_mutex_t	*right_f;
	pthread_mutex_t	mut_state;
	pthread_mutex_t	nb_meals_eaten;
	pthread_mutex_t	mut_last_meal;
	size_t			last_eat_time;
}			t_philo;

typedef struct s_data
{
	int				nb_philos;
	int				nb_meals;
	int				nb_full_philos;
	bool			keep;
	bool			flag;
	size_t			eat_time;
	size_t			time_to_die;
	size_t			sleep_time;
	size_t			start_time;
	pthread_mutex_t	mut_meal;
	pthread_mutex_t	mut_die;
	pthread_mutex_t	mut_sleep;
	pthread_mutex_t	mut_write;
	pthread_mutex_t	mut_keep_iter;
	pthread_mutex_t	mut_start_time;
	pthread_mutex_t	flag_mut;
	pthread_t		monitor;
	pthread_t		monit_all_full;
	pthread_t		*philo_thrd;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}				t_data;

// routine.c
void		*routine(void *philo_p);
bool		philo_died(t_philo *philo);

// parse.c
int			check_input(int argc, char **argv);
int			wrong_input_check(int argc, char **argv);
void		print_instruction(void);

//parse_utils.c
int			ft_atoi(const char *str);
int			ft_isspace(char c);
int			ft_isdigit(char c);

// init_data.c
int			init_data(t_data *data, int argc, char **argv);
int			init_philos(t_data *data);
int			init_forks(t_data *data);

// eat_1.c
int			eat(t_philo *philo);

// eat_2.c
int			take_forks(t_philo *philo);
int			take_right_fork(t_philo *philo);
int			take_left_fork(t_philo *philo);
int			take_forks(t_philo *philo);
void		drop_forks(t_philo *philo);
void		sleep_for_eating(t_philo *philo);

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

// utils.c
void		free_data(t_data *data);
void		print_msg(t_data *data, int id, char *msg);
int			handle_1_philo(t_philo *philo);

// time.c
size_t		get_time(void);
void		ft_usleep(t_data *data);

#endif