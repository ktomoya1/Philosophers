/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 08:20:44 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/14 11:23:46 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_alive_all(t_philo philos[])
{
	int	i;

	i = 0;
	while (i < philos->shared->num_of_philos)
	{
		if (philos[0].shared->condition == is_alive_and_eating
			&& has_eaten(&philos[i]) == true)
		{
			i++;
			continue ;
		}
		if (is_alive(&philos[i]) == false)
			return (false);
		if (is_hungry(&philos[i]) == true)
		{
			die(&philos[i]);
			return (false);
		}
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
	while (get_cur_time() < philos[0].shared->program_start)
		usleep(1);
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
