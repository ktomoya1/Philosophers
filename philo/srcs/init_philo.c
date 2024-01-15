/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:02:08 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/15 16:29:25 by ktomoya          ###   ########.fr       */
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
		philos[i].forks_in_hand = 0;
		philos[i].time_to_die = ft_atoi(argv[2]);
		philos[i].shared = shared;
		i++;
	}
}
