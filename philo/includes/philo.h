/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:46:22 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/16 15:28:48 by ktomoya          ###   ########.fr       */
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
	useconds_t		time_to_die;
	useconds_t		time_to_eat;
	useconds_t		time_to_sleep;
	useconds_t		start_time;
	pthread_mutex_t	someone_dead_mutex;
	pthread_mutex_t	*is_full_mutex;
	pthread_mutex_t	*meal_time_mutex;
	pthread_mutex_t	*forks;
};

struct s_philo
{
	int			id;
	int			lfork_id;
	int			rfork_id;
	int			meal_count;
	bool		is_full;
	bool		is_dead;
	bool		someone_dead;
	t_info		*info;
	useconds_t	last_meal_time;
};

// checker.c
int		check_input(int argc, char *argv[]);

// libft.c
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *s);

// print.c
int		put_error(const char *format, int error_code);

#endif
