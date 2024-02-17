/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:18:12 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/17 11:02:37 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_info *info, t_philo *philo)
{
	if (info)
	{
		if (info->threads)
			free(info->threads);
		if (info->is_full_mutex)
			free(info->is_full_mutex);
		if (info->meal_time_mutex)
			free(info->meal_time_mutex);
		if (info->forks)
			free(info->forks);
		free(info);
		info = NULL;
	}
	if (philo)
	{
		free(philo);
		philo = NULL;
	}
}
