/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:38:41 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/22 15:43:45 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_info *info)
{
	int	i;

	if (pthread_mutex_init(&info->someone_dead_mutex, NULL) != SUCCESS)
		return (puterror_and_free("pthread_mutex_init error", info, NULL));
	if (pthread_mutex_init(&info->print_mutex, NULL) != SUCCESS)
		return (puterror_and_free("pthread_mutex_init error", info, NULL));
	if (pthread_mutex_init(&info->is_full_all_mutex, NULL) != SUCCESS)
		return (puterror_and_free("pthread_mutex_init error", info, NULL));
	i = 0;
	while (i < info->num_of_philos)
	{
		if (pthread_mutex_init(&info->is_full_mutex[i], NULL) != SUCCESS)
			return (puterror_and_free("pthread_mutex_init error", info, NULL));
		if (pthread_mutex_init(&info->time_mutex[i], NULL) != SUCCESS)
			return (puterror_and_free("pthread_mutex_init error", info, NULL));
		if (pthread_mutex_init(&info->forks[i], NULL) != SUCCESS)
			return (puterror_and_free("pthread_mutex_init error", info, NULL));
		i++;
	}
	return (SUCCESS);
}
