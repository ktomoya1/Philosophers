/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 09:48:20 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/20 15:45:53 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_info *info, t_philo *philos, int philo_count)
{
	int	status;
	int	i;

	i = 0;
	info->start_time = get_time() + 1000;
	while (i < philo_count)
	{
		status = pthread_create(&info->threads[i], NULL, routine, &philos[i]);
		if (i == 10)
		{
			pthread_mutex_lock(&info->someone_dead_mutex);
			info->someone_dead = true;
			pthread_mutex_unlock(&info->someone_dead_mutex);
			join_threads(info, philos, i);
			return (destroy_and_free("pthread_create error", info, philos));
		}
		i++;
	}
	return (SUCCESS);
}

int	join_threads(t_info *info, t_philo *philos, int philo_count)
{
	int	status;
	int	i;

	i = 0;
	while (i < philo_count)
	{
		status = pthread_join(info->threads[i], NULL);
		if (status != SUCCESS)
			return (destroy_and_free("pthread_join error", info, philos));
		i++;
	}
	return (SUCCESS);
}

int	run_threads(t_info *info, t_philo *philos)
{
//	int	i;
//	int	count;
//	int	status;

//	i = 0;
//	count = 0;
//	while (i < info->num_of_philos)
//	{
//		status = pthread_create(&info->threads[i], NULL, routine, &philos[i]);
//		if (status != SUCCESS)
//		{
//			pthread_mutex_lock(&info->someone_dead_mutex);
//			info->someone_dead = true;
//			pthread_mutex_unlock(&info->someone_dead_mutex);
//			join(info, i);
//			return (destroy_and_free("pthread_create error", info, philos));
//		}
//		i++;
//		count++;
//	}
	create_threads(info, philos, info->num_of_philos);
	monitor(info, philos);
	join_threads(info, philos, info->num_of_philos);
	//i = 0;
	//while (i < count)
	//{
	//	status = pthread_join(info->threads[i], NULL);
	//	if (status != SUCCESS)
	//		return (destroy_and_free("pthread_join error", info, philos));
	//	i++;
	//}
	return (SUCCESS);
}
