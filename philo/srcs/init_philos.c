/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:13:56 by ktomoya           #+#    #+#             */
/*   Updated: 2023/12/25 16:29:33 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(pthread_t philos[], int max_size)
{
	int	i;

	i = 0;
	while (i < max_size)
	{
		philos[i] = 0;
		i++;
	}
}