/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:02:32 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/12 20:05:28 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*think(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (*philo->is_dead == true)
		return ((void *)1);
	printf("%ld %d is thinking\n", gettime_in_ms(), philo->id);
	usleep(philo->time_to_die);
	if (*philo->is_dead == true)
		return ((void *)1);
	*philo->is_dead = true;
	printf("%ld %d died\n", gettime_in_ms(), philo->id);
	return ((void *)1);
}
