/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:14:04 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/03 06:57:54 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	assign_fork_id(t_philo *philo)
{
	int	fork_id;

	if (philo->id % 2 == 1)
	{
		if (philo->fork_count == 0)
			fork_id = philo->id - 1;
		else if (philo->fork_count == 1 && philo->id == 1)
			fork_id = philo->shared->num_of_philos - 1;
		else
			fork_id = philo->id - 2;
	}
	else
	{
		if (philo->fork_count == 0)
			fork_id = philo->id - 2;
		else
			fork_id = philo->id - 1;
	}
	if (philo->fork_count == 0)
		philo->left_fork = &philo->shared->forks[fork_id];
	if (philo->fork_count == 1)
		philo->right_fork = &philo->shared->forks[fork_id];
}

void	take_a_fork(t_philo *philo)
{
	if (philo->fork_count == 0)
		pthread_mutex_lock(philo->left_fork);
	else if (philo->fork_count == 1)
		pthread_mutex_lock(philo->right_fork);
	philo->fork_count++;
	print_message(philo, "has taken a fork");
}

void	release_fork(t_philo *philo)
{
	philo->fork_count = 0;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->shared->meal_count[philo->id]);
	if (philo->meal_count == 0)
	{
		pthread_mutex_lock(&philo->shared->time_mutex);
		philo->start_time = get_cur_time();
		pthread_mutex_unlock(&philo->shared->time_mutex);
	}
	pthread_mutex_unlock(&philo->shared->meal_count[philo->id]);
	assign_fork_id(philo);
	take_a_fork(philo);
	assign_fork_id(philo);
	take_a_fork(philo);
}
