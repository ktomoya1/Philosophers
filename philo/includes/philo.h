/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:46:22 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/27 15:10:15 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include <errno.h>
# include <stdbool.h>

# define PHILO_MAX 20
# define USLEEP_MAX 1000000

# define SUCCESS 0
# define FAILURE 1
# define ERROR -1

typedef struct s_shared_data
{
	int				num_of_philos;
	bool			death_flag;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	forks[PHILO_MAX];
}	t_shared_data;

typedef struct s_philo
{
	int				id;
	int				forks_in_hand;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	useconds_t		start_time;
	useconds_t		time_to_die;
	useconds_t		time_to_eat;
	useconds_t		time_to_sleep;
	t_shared_data	*shared;
}	t_philo;

int				validate_input(int argc, char *argv[]);
bool			has_nondigits(const char *s);

int				create_thread(pthread_t threads[], t_philo philos[]);
t_shared_data	*setup_shared_data(int num_of_philos);
void			init_philo(t_philo philos[], char *argv[], t_shared_data *shared);
int				wait_thread(pthread_t threads[]);

long			gettime_in_ms(void);
void			*philo_routine(void *arg);
void			think(t_philo *philo);
int				assign_fork_id(t_philo *philo);
void			take_a_fork(t_philo *philo, int fork_id);
void			take_forks(t_philo *philo);
void			eat(t_philo *philo);
void			release_fork(t_philo *philo);
void			fall_asleep(t_philo *philo);
bool			is_hungry(t_philo *philo);
bool			is_dead(t_philo *philo);
void			die(t_philo *philo);
void			print_message(t_philo *philo, const char *msg);

void			put_error(const char *format);
int				put_err_ret(int error_code, const char *format);
void			*free_ret_nul(void *ptr);

int				ft_isspace(int c);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
int				ft_atoi(const char *s);

#endif
