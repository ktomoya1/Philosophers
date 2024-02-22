/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:55:43 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/22 15:27:25 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	pthread_mutex_lock(&philo->info->time_mutex[philo->id - 1]);
	philo->last_meal_time = philo->info->start_time;
	pthread_mutex_unlock(&philo->info->time_mutex[philo->id - 1]);
	while (get_time() < philo->info->start_time)
		usleep(1);
	if (philo->info->someone_dead == true)
	   return ((void *)1);
	if (philo->info->num_of_philos == 1)
	{
		print_message("has_taken a fork", philo);
		ft_usleep(philo->info->time_to_die);
		return ((void *)1);
	}
	if (philo->id % 2 == 0)
		ft_usleep(philo->info->time_to_eat / 2);
	while (true)
	{
		eat(philo);
		sleeping(philo);
		think(philo);
		if (philo->info->cond(philo) == true)
			break ;
	}
	return ((void *)1);
}
