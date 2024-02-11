/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:44:43 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/11 12:24:33 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_hungry(t_philo *philo)
{
	useconds_t	elapsed_time;

	pthread_mutex_lock(&philo->shared->time_mutex[philo->id - 1]);
	elapsed_time = get_cur_time() - philo->start_time;
	pthread_mutex_unlock(&philo->shared->time_mutex[philo->id - 1]);
	pthread_mutex_lock(&philo->shared->meal_count[philo->id - 1]);
	if (philo->meal_count == 0)
	{
		pthread_mutex_unlock(&philo->shared->meal_count[philo->id - 1]);
		if (elapsed_time > philo->time_to_die)
			return (true);
	}
	else
	{
		pthread_mutex_unlock(&philo->shared->meal_count[philo->id - 1]);
		if (elapsed_time > philo->time_to_die + philo->time_to_eat)
			return (true);
	}
	pthread_mutex_unlock(&philo->shared->meal_count[philo->id - 1]);
	return (false);
}

bool	has_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->shared->full_mutex[philo->id - 1]);
	if (philo->is_full == true)
	{
		pthread_mutex_unlock(&philo->shared->full_mutex[philo->id - 1]);
		return (true);
	}
	pthread_mutex_unlock(&philo->shared->full_mutex[philo->id - 1]);
	return (false);
}

bool	is_alive(t_philo *philo)
{
	bool	is_alive;

	pthread_mutex_lock(&philo->shared->death_mutex);
	if (philo->shared->death_flag == false)
		is_alive = true;
	else
		is_alive = false;
	pthread_mutex_unlock(&philo->shared->death_mutex);
	return (is_alive);
}

bool	is_alive_and_eating(t_philo *philo)
{
	return (is_alive(philo) == true && has_eaten(philo) == false);
}
