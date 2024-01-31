/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:50:38 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/31 10:58:23 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->shared->num_of_philos == 1)
	{
		ft_usleep(philo->time_to_die);
		die(philo);
		return ((void *)1);
	}
	while (philo->shared->condition(philo) == true)
	{
		think(philo);
		take_forks(philo);
		eat(philo);
		release_fork(philo);
		fall_asleep(philo);
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
	ft_usleep(philo->time_to_eat);
}

void	fall_asleep(t_philo *philo)
{
	print_message(philo, "is sleeping");
	ft_usleep(philo->time_to_sleep);
}

void	think(t_philo *philo)
{
	print_message(philo, "is thinking");
}

void	die(t_philo *philo)
{
	if (is_alive(philo) == false)
		return ;
	pthread_mutex_lock(&philo->shared->death_mutex);
	philo->shared->death_flag = true;
	pthread_mutex_unlock(&philo->shared->death_mutex);
	pthread_mutex_lock(&philo->shared->print_mutex);
	printf("%d %d died\n",
		get_cur_time() - philo->shared->program_start, philo->id);
	pthread_mutex_unlock(&philo->shared->print_mutex);
}
