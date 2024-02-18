/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:55:43 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/18 17:19:59 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (get_time() < philo->info->start_time)
		usleep(1);
	if (philo->id % 2 == 0)
		ft_usleep(philo->info->time_to_eat / 2);
	while (true)
	{
		eat(philo);
		sleeping(philo);
		think(philo);
		if (philo->info->cond == false)
			break ;
	}
	return ((void *)1);
}
