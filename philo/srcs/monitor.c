/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:54:27 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/18 17:01:34 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(t_info *info, t_philo *philos)
{
	int	full_count;
	int	i;

	i = 0;
	full_count = 0;
	ft_usleep(info->time_to_die);
	while (true)
	{
		if (is_dead(&philos[i]) == true)
		{
			die(&philos[i]);
			return ;
		}
		if (info->cond == is_dead_or_full_all && is_full(&philos[i]) == true)
			full_count++;
		if (full_count == info->num_of_philos)
		{
			pthread_mutex_lock(&info->is_full_all_mutex);
			info->is_full_all = true;
			pthread_mutex_unlock(&info->is_full_all_mutex);
			return ;
		}
		if (i == info->num_of_philos - 1)
			i = 0;
		i++;
	}
}
