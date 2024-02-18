/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 09:48:20 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/18 14:39:52 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	run_threads(t_info *info, t_philo *philos)
{
	int			status;
	int			i;

	i = 0;
	info->start_time = get_time() + philos->info->num_of_philos * 5;
	while (i < info->num_of_philos)
	{
		status = pthread_create(&info->threads[i], NULL, routine, &philos[i]);
		if (status != SUCCESS)
			return (destroy_and_free("pthread_create error", info, philos));
		i++;
	}
	if (get_time() < info->start_time)
		usleep(1);
	monitor(info, philos);
	i = 0;
	while (i < info->num_of_philos)
	{
		status = pthread_join(info->threads[i], NULL);
		if (status != SUCCESS)
			return (destroy_and_free("pthread_join error", info, philos));
		i++;
	}
	return (SUCCESS);
}
