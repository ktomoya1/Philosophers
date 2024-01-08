/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:46:22 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/08 15:21:56 by ktomoya          ###   ########.fr       */
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

typedef struct s_philo
{
	int				id;
}	t_philo;

int		validate_input(int argc, char *argv[]);
int		check_num_of_philos(int *n_philos, const char *s);
int		check_time_to_die(useconds_t *time_to_die, const char *s);
int		nonnegative_atoi(const char *s);
int		validate_pthread_count(int n_philos);

bool	has_nondigits(const char *s);

int		create_philos(pthread_t philos[], int n_philos);
void	init_philos(pthread_t philos[], int n_philos);
int		set_philo_value(t_philo *philo, int philo_id);
int		destroy_philos(pthread_t philos[]);

long	gettime_in_ms(void);
void	*think(void *arg);

void	put_syserr(int errnum, const char *format);
void	put_error(const char *format);
int		put_err_ret(int error_code, const char *format);
int		set_errno_ret(int error_code, int errno_num);

int		ft_isspace(int c);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *s);

#endif
