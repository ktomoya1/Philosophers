/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_shared_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:19:56 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/15 17:11:55 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_shared_data	*setup_shared_data(int num_of_philos)
{
	t_shared_data	*shared;

	shared = (t_shared_data *)malloc(sizeof(t_shared_data));
	if (shared == NULL)
		return (NULL);
	shared->num_of_philos = num_of_philos;
	shared->is_dead = false;
	memset(shared->fork, true, sizeof(bool) * PHILO_MAX);
	return (shared);
}
