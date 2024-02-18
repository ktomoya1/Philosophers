/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:38:36 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/18 15:40:14 by ktomoya          ###   ########.fr       */
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

# define USLEEP_MAX 1000000

# define SUCCESS 0
# define FAILURE 1
# define ERROR -1

typedef struct s_info	t_info;
typedef struct s_philo	t_philo;

struct s_info
{
	int				num_of_philos;
	int				minimum_meal_count;
	bool			someone_dead;
	pthread_t		*threads;
	useconds_t		time_to_die;
	useconds_t		time_to_eat;
	useconds_t		time_to_sleep;
	useconds_t		start_time;
	pthread_mutex_t	someone_dead_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*is_full_mutex;
	pthread_mutex_t	*meal_time_mutex;
	pthread_mutex_t	*forks;
};

struct s_philo
{
	int				id;
	int				meal_count;
	bool			is_full;
	t_info			*info;
	useconds_t		last_meal_time;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
};

// checker.c
int			check_input(int argc, char *argv[]);

// libft.c
size_t		ft_strlen(const char *s);
int			ft_atoi(const char *s);

// print.c
void		print_message(const char *msg, t_philo *philo);
int			put_error(const char *format, int error_code);

// init.c
int			init_info(t_info **info_ptr, int argc, char *argv[]);
int			init_philos(t_philo **philos_ptr, t_info *info);

// free.c
void		free_all(t_info *info, t_philo *philo);

// utils.c
int			puterror_and_free(const char *format, t_info *info, t_philo *philos);
int			destroy_and_free(const char *format, t_info *info, t_philo *philos);

// mutex.c
int			init_mutex(t_info *info);
void		destroy_mutex(t_info *info);

// thread.c
int			run_threads(t_info *info, t_philo *philos);

// routine.c
void		*routine(void *args);

// time.c
useconds_t	get_time(void);
void		ft_usleep(useconds_t time);

// bool.c
bool		is_dead(t_philo *philo);
bool		someone_dead(t_philo *philo);

// monitor.c
void		monitor(t_info *info, t_philo *philos);

// action.c
void		die(t_philo *philo);
void		eat(t_philo *philo);
void		sleeping(t_philo *philo);
void		think(t_philo *philo);

#endif
