/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:13:56 by ktomoya           #+#    #+#             */
/*   Updated: 2023/12/07 16:27:41 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philos(t_philo philos[], int n_philos)
{
	int	i;

	i = 0;
	while (i < n_philos)
	{
		philos[i].id = 0;
		i++;
	}
	return (philos);
}
