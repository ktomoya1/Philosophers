/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:02:14 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/18 15:53:50 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	die(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->print_mutex);
	pthread_mutex_lock(&philo->info->someone_dead_mutex);
	philo->info->someone_dead = true;
	printf("%d %d died\n",
			get_time() - philo->info->start_time, philo->id);
	pthread_mutex_unlock(&philo->info->someone_dead_mutex);
	pthread_mutex_unlock(&philo->info->print_mutex);
}

void	eat(t_philo *philo)
{
	if (philo->meal_count == 0)
	{
		pthread_mutex_lock(&philo->info->meal_time_mutex[philo->id - 1]);
		philo->last_meal_time = get_time();
		pthread_mutex_unlock(&philo->info->meal_time_mutex[philo->id - 1]);
	}
	pthread_mutex_lock(philo->left_fork);
	print_message("has taken a fork", philo);
	pthread_mutex_lock(philo->right_fork);
	print_message("has taken a fork", philo);
	pthread_mutex_lock(&philo->info->meal_time_mutex[philo->id - 1]);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->info->meal_time_mutex[philo->id - 1]);
	print_message("is eating", philo);
	ft_usleep(philo->info->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	philo->meal_count++;
}

void	sleeping(t_philo *philo)
{
	print_message("is sleeping", philo);
	ft_usleep(philo->info->time_to_sleep);
}

void	think(t_philo *philo)
{
	print_message("is thinking", philo);
}
