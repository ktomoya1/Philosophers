/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:46:22 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/13 19:43:09 by ktomoya          ###   ########.fr       */
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
	bool	is_dead;
	bool	fork[PHILO_MAX];
}	t_shared_data;

typedef struct s_philo
{
	int				id;
	useconds_t		time_to_die;
	t_shared_data	*shared;
}	t_philo;

int		validate_input(int argc, char *argv[]);
bool	has_nondigits(const char *s);

int		create_thread(pthread_t threads[], t_philo philos[], int philo_count);
int		setup_shared_data(t_shared_data **shared, int size);
void	init_philo(t_philo philos[], char *argv[], t_shared_data *shared);
int		wait_thread(pthread_t threads[]);

long	gettime_in_ms(void);
void	*philo_routine(void *arg);
void	think(t_philo *philo);
void	take_left_fork(t_philo *philo);
void	die(t_philo *philo);

void	put_error(const char *format);
int		put_err_ret(int error_code, const char *format);

int		ft_isspace(int c);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *s);

#endif
