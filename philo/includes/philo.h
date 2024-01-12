/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:46:22 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/12 20:39:40 by ktomoya          ###   ########.fr       */
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
	int			id;
	useconds_t	time_to_die;
	bool		*is_dead;
}	t_philo;

int		validate_input(int argc, char *argv[]);
bool	has_nondigits(const char *s);

int		create_thread(pthread_t threads[], t_philo philos[], int philo_count);
int		setup_philo(t_philo philos[], char *argv[], int philo_count);
int		wait_thread(pthread_t threads[]);

long	gettime_in_ms(void);
void	*think(void *arg);

void	put_error(const char *format);
int		put_err_ret(int error_code, const char *format);

int		ft_isspace(int c);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *s);

#endif
