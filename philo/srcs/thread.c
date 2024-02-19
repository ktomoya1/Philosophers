/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 09:48:20 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/19 12:07:03 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	run_threads(t_info *info, t_philo *philos)
{
	int			status;
	int			i;

	i = 0;
	info->start_time = get_time() + 1000;
	while (i < info->num_of_philos)
	{
		status = pthread_create(&info->threads[i], NULL, routine, &philos[i]);
		if (status != SUCCESS)
			return (destroy_and_free("pthread_create error", info, philos));
		i++;
	}
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
