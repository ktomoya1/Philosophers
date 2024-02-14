/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:14:04 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/13 17:03:14 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	assign_fork_id(t_philo *philo)
{
	philo->first_fork = philo->id - 1;
	if (philo->id == 1)
		philo->second_fork = philo->shared->num_of_philos - 1;
	else
		philo->second_fork = philo->id - 2;
}

void	take_a_fork(t_philo *philo)
{
	if (philo->fork_count == 0)
		pthread_mutex_lock(&philo->shared->forks[philo->first_fork]);
	else if (philo->fork_count == 1)
		pthread_mutex_lock(&philo->shared->forks[philo->second_fork]);
	philo->fork_count++;
	print_message(philo, "has taken a fork");
}

void	release_fork(t_philo *philo)
{
	philo->fork_count = 0;
	pthread_mutex_unlock(&philo->shared->forks[philo->second_fork]);
	pthread_mutex_unlock(&philo->shared->forks[philo->first_fork]);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->shared->meal_count[philo->id - 1]);
	if (philo->meal_count == 0)
	{
		pthread_mutex_unlock(&philo->shared->meal_count[philo->id - 1]);
		pthread_mutex_lock(&philo->shared->time_mutex[philo->id - 1]);
		philo->start_time = get_cur_time();
		pthread_mutex_unlock(&philo->shared->time_mutex[philo->id - 1]);
	}
	pthread_mutex_unlock(&philo->shared->meal_count[philo->id - 1]);
	take_a_fork(philo);
	take_a_fork(philo);
}
