/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:44:43 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/29 18:47:38 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_hungry(t_philo *philo)
{
	useconds_t	elapsed_time;

	elapsed_time = get_cur_time() - philo->start_time;
	if (elapsed_time > philo->time_to_die)
		return (true);
	return (false);
}

bool	has_eaten(t_philo *philo)
{
	if (philo->meal_count == philo->minimum_meal_count)
		return (true);
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