/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:54:27 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/19 08:12:06 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	monitor_is_dead(t_info *info, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < info->num_of_philos)
	{
		if (is_dead(&philos[i]) == true)
			return (true);
		i++;
	}
	return (false);
}

static bool	monitor_is_full_all(t_info *info, t_philo *philos)
{
	int	i;

	if (info->cond == someone_dead)
		return (false);
	i = 0;
	while (i < info->num_of_philos)
	{
		if (is_full(&philos[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

void	monitor(t_info *info, t_philo *philos)
{
	int	i;

	i = 0;
	ft_usleep(info->time_to_die);
	while (true)
	{
		if (monitor_is_dead(info, philos) == true)
		{
			die(&philos[i]);
			break ;
		}
		if (monitor_is_full_all(info, philos) == true)
		{
			pthread_mutex_lock(&info->is_full_all_mutex);
			info->is_full_all = true;
			pthread_mutex_unlock(&info->is_full_all_mutex);
			break ;
		}
	}
}
