/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 08:20:44 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/03 11:56:10 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_alive_all(t_philo philos[])
{
	int	i;

	i = 0;
	while (i < philos->shared->num_of_philos)
	{
		if (is_alive(&philos[i]) == false)
			return (false);
		pthread_mutex_lock(&philos[i].shared->time_mutex);
		if (get_cur_time() - philos[i].start_time > philos[i].time_to_die)
		{
			pthread_mutex_unlock(&philos[i].shared->time_mutex);
			die(&philos[i]);
			return (false);
		}
		pthread_mutex_unlock(&philos[i].shared->time_mutex);
		i++;
	}
	return (true);
}

static bool	has_eaten_all(t_philo philos[])
{
	int	i;

	i = 0;
	while (i < philos->shared->num_of_philos)
	{
		if (has_eaten(&philos[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

void	monitor(t_philo philos[])
{
	ft_usleep(philos[0].time_to_die);
	while (true)
	{
		if (is_alive_all(philos) == false)
		{
			break ;
		}
		if (philos[0].shared->condition == is_alive_and_eating
			&& has_eaten_all(philos) == true)
		{
			break ;
		}
	}
}
