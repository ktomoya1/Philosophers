/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:50:38 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/30 12:49:57 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->shared->condition(philo) == true)
	{
		take_forks(philo);
		eat(philo);
		release_fork(philo);
		fall_asleep(philo);
		think(philo);
	}
	return ((void *)1);
}

void	eat(t_philo *philo)
{
	if (is_hungry(philo) == true)
	{
		die(philo);
		return ;
	}
	philo->meal_count++;
	print_message(philo, "is eating");
	usleep(philo->time_to_eat * 1000);
}

void	fall_asleep(t_philo *philo)
{
	if (has_eaten(philo) == true)
		return ;
	print_message(philo, "is sleeping");
	usleep(philo->time_to_sleep * 1000);
}

void	think(t_philo *philo)
{
	if (has_eaten(philo) == true)
		return ;
	print_message(philo, "is thinking");
	usleep(philo->time_to_die * 1000);
}

void	die(t_philo *philo)
{
	if (is_alive(philo) == false)
		return ;
	pthread_mutex_lock(&philo->shared->death_mutex);
	philo->shared->death_flag = true;
	pthread_mutex_unlock(&philo->shared->death_mutex);
	printf("\033[31m%d %d has died\033[0m\n", get_cur_time() - philo->shared->program_start, philo->id);
}
