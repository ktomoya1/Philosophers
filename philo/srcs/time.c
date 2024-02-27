/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:06:10 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/27 11:23:02 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

useconds_t	get_time(void)
{
	struct timeval	ms_time;

	if (gettimeofday(&ms_time, NULL) == ERROR)
		return (put_error("gettimeofday error", FAILURE));
	return (ms_time.tv_sec * 1000 + ms_time.tv_usec / 1000);
}

void	ft_usleep(useconds_t time)
{
	useconds_t	end_time;

	end_time = get_time() + time;
	while (end_time > get_time())
	{
		usleep((end_time - get_time()) / 4 * 1000);
	}
}

void	wait_first_meal(t_philo *philo)
{
	int	n;
	int	id;
	int	k;
	int	unit;

	n = philo->info->num_of_philos;
	if (n == 1)
		return ;
	id = philo->id;
	k = n / 2;
	unit = philo->info->time_to_eat / k;
	if (unit == 0)
		unit = 1;
	ft_usleep(unit * ((id * k) % n));
}
