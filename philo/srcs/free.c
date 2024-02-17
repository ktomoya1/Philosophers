/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:18:12 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/17 08:50:57 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_info *info, t_philo *philo)
{
	if (info)
	{
		if (info->is_full_mutex)
		{
			free(info->is_full_mutex);
			info->is_full_mutex = NULL;
		}
		if (info->meal_time_mutex)
		{
			free(info->meal_time_mutex);
			info->meal_time_mutex = NULL;
		}
		if (info->forks)
		{
			free(info->forks);
			info->forks = NULL;
		}
		free(info);
		info = NULL;
	}
	if (philo)
	{
		free(philo);
		philo = NULL;
	}
}
