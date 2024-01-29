/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:02:08 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/29 15:15:12 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_philo philos[], char *argv[], t_shared_data *shared)
{
	int			i;

	i = 0;
	while (i < shared->num_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].fork_count = 0;
		philos[i].right_fork = NULL;
		philos[i].left_fork = NULL;
		philos[i].meal_count = 0;
		philos[i].start_time = 0;
		philos[i].time_to_die = ft_atoi(argv[2]);
		philos[i].time_to_eat = ft_atoi(argv[3]);
		philos[i].time_to_sleep = ft_atoi(argv[4]);
		if (argv[5] == NULL)
			philos[i].minimum_meal_count = 0;
		else
			philos[i].minimum_meal_count = ft_atoi(argv[5]);
		philos[i].shared = shared;
		i++;
	}
}
