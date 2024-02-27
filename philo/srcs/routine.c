/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:55:43 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/27 12:10:40 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (get_time() < philo->info->start_time)
		usleep(1);
	if (philo->info->someone_dead == true)
		return ((void *)1);
	if (philo->info->num_of_philos == 1)
	{
		print_message("has taken a fork", philo);
		ft_usleep(philo->info->time_to_die);
		return ((void *)1);
	}
	wait_first_meal(philo);
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
