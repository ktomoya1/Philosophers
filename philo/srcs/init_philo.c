/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:02:08 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/13 16:34:38 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_philo philos[], char *argv[], t_shared_data *shared)
{
	int			philo_count;
	useconds_t	time_to_die;
	int			i;

	philo_count = ft_atoi(argv[1]);
	time_to_die = ft_atoi(argv[2]);
	i = 0;
	while (i < philo_count)
	{
		philos[i].id = i + 1;
		philos[i].time_to_die = time_to_die;
		philos[i].shared = shared;
		i++;
	}
}
