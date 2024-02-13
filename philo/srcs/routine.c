/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:50:38 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/13 15:27:43 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (get_cur_time() < philo->shared->program_start)
		usleep(1);
	if (philo->shared->num_of_philos == 1)
	{
		print_message(philo, "has taken a fork");
		ft_usleep(philo->time_to_die);
		return ((void *)1);
	}
	if (philo->id % 2 == 0)
		ft_usleep(philo->time_to_eat / 2);
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
	pthread_mutex_lock(&philo->shared->time_mutex[philo->id - 1]);
	philo->start_time = get_cur_time();
	pthread_mutex_unlock(&philo->shared->time_mutex[philo->id - 1]);
	pthread_mutex_lock(&philo->shared->meal_count[philo->id - 1]);
	philo->meal_count++;
	pthread_mutex_unlock(&philo->shared->meal_count[philo->id - 1]);
	print_message(philo, "is eating");
	ft_usleep(philo->time_to_eat);
}

void	fall_asleep(t_philo *philo)
{
	if (philo->shared->condition == is_alive_and_eating
		&& has_eaten(philo) == true)
		return ;
	print_message(philo, "is sleeping");
	ft_usleep(philo->time_to_sleep);
}

void	think(t_philo *philo)
{
	if (philo->shared->condition == is_alive_and_eating
		&& has_eaten(philo) == true)
		return ;
	if (is_hungry(philo) == true)
		return ;
	print_message(philo, "is thinking");
}

void	die(t_philo *philo)
{
	if (is_alive(philo) == false)
		return ;
	pthread_mutex_lock(&philo->shared->print_mutex);
	printf("%d %d died\n",
		get_cur_time() - philo->shared->program_start, philo->id);
	pthread_mutex_unlock(&philo->shared->print_mutex);
	pthread_mutex_lock(&philo->shared->death_mutex);
	philo->shared->death_flag = true;
	pthread_mutex_unlock(&philo->shared->death_mutex);
}
