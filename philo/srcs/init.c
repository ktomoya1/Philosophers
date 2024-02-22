/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:40:09 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/22 16:55:38 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_info(t_info **info_ptr, int argc, char *argv[])
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (info == NULL)
		return (puterror_and_free("malloc error", info, NULL));
	memset(info, 0, sizeof(t_info));
	info->num_of_philos = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->cond = someone_dead;
	if (argc == 6)
	{
		info->minimum_meal_count = ft_atoi(argv[5]);
		info->cond = someone_dead_or_full_all;
	}
	info->threads = malloc(sizeof(pthread_t) * info->num_of_philos);
	info->is_full_mutex = malloc(sizeof(pthread_mutex_t) * info->num_of_philos);
	info->time_mutex = malloc(sizeof(pthread_mutex_t) * info->num_of_philos);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_of_philos);
	if (info->threads == NULL || info->is_full_mutex == NULL
		|| info->time_mutex == NULL || info->forks == NULL)
		return (puterror_and_free("malloc error", info, NULL));
	*info_ptr = info;
	return (SUCCESS);
}

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

int	init_philos(t_philo **philos_ptr, t_info *info)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philos);
	if (philos == NULL)
		return (puterror_and_free("malloc error", info, NULL));
	memset(philos, 0, sizeof(t_philo));
	i = 0;
	while (i < info->num_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].info = info;
		philos[i].left_fork = &info->forks[i];
		if (philos[i].id == 1)
			philos[i].right_fork = &info->forks[info->num_of_philos - 1];
		else
			philos[i].right_fork = &info->forks[i - 1];
		i++;
	}
	*philos_ptr = philos;
	return (SUCCESS);
}
