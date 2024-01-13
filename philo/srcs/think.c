/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:32:15 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/13 19:39:50 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	if (philo->shared->is_dead == true)
		return ;
	printf("%ld %d is thinking\n", gettime_in_ms(), philo->id);
	usleep(philo->time_to_die);
}
