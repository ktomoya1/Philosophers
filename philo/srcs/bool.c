/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:58:51 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/18 15:57:31 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->meal_time_mutex[philo->id - 1]);
	if (get_time() - philo->last_meal_time > philo->info->time_to_die)
	{
		pthread_mutex_unlock(&philo->info->meal_time_mutex[philo->id - 1]);
		return (true);
	}
	pthread_mutex_unlock(&philo->info->meal_time_mutex[philo->id - 1]);
	return (false);
}

bool	someone_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->someone_dead_mutex);
	if (philo->info->someone_dead == true)
	{
		pthread_mutex_unlock(&philo->info->someone_dead_mutex);
		return (true);
	}
	pthread_mutex_unlock(&philo->info->someone_dead_mutex);
	return (false);
}
