/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_shared_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:19:56 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/26 15:28:52 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_shared_data	*setup_shared_data(int num_of_philos)
{
	t_shared_data	*shared;
	int				i;

	shared = (t_shared_data *)malloc(sizeof(t_shared_data));
	if (shared == NULL)
		return (NULL);
	shared->num_of_philos = num_of_philos;
	shared->death_flag = false;
	if (pthread_mutex_init(&shared->death_mutex, NULL) != SUCCESS)
		return (free_ret_nul(shared));
	i = 0;
	while (i < num_of_philos)
	{
		if (pthread_mutex_init(&shared->forks[i], NULL) != SUCCESS)
			return (free_ret_nul(shared));
		i++;
	}
	return (shared);
}
