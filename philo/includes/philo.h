/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:46:22 by ktomoya           #+#    #+#             */
/*   Updated: 2023/12/08 15:24:34 by ktomoya          ###   ########.fr       */
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

# define PHILO_MAXSIZE 1

# define SUCCESS 0
# define FAILURE 1
# define ERROR -1

typedef struct s_philo
{
	int				id;
}	t_philo;

int		check_input(int argc, char *argv[]);
int		nonnegative_atoi(const char *s);
int		validate_pthread_count(int n_philos);

t_philo	*create_philos(int n_philos);
t_philo	*init_philos(t_philo philos[], int n_philos);
int		set_philo_value(t_philo *philo, int	philo_id);

void	put_syserr(int errnum, const char *format);
void	put_error(const char *format);
int		put_err_ret(int error_code, const char *format);
int		set_errno_ret(int error_code, int errno_num);

int		ft_isspace(int c);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);

#endif
