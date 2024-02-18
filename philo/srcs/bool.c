/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:58:51 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/18 17:05:42 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->meal_time_mutex[philo->id - 1]);
	if (get_time() - philo->last_meal_time > philo->info->time_to_die)
	{
		printf("cur: %u, last_eat_time: %u, cur - last: %d\n", get_time(), philo->last_meal_time, get_time() - philo->last_meal_time);
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

bool	is_full(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->is_full_mutex[philo->id - 1]);
	if (philo->is_full == true)
	{
		pthread_mutex_unlock(&philo->info->is_full_mutex[philo->id - 1]);
		return (true);
	}
	pthread_mutex_unlock(&philo->info->is_full_mutex[philo->id - 1]);
	return (false);
}

bool	is_full_all(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->is_full_all_mutex);
	if (philo->info->is_full_all == true)
	{
		pthread_mutex_unlock(&philo->info->is_full_all_mutex);
		return (true);
	}
	pthread_mutex_unlock(&philo->info->is_full_all_mutex);
	return (false);
}

bool	is_dead_or_full_all(t_philo *philo)
{
	if (is_dead(philo) == true)
		return (true);
	if (is_full_all(philo) == true)
		return (true);
	return (false);
}
