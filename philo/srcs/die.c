/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:40:46 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/27 15:25:35 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	die(t_philo *philo)
{
	if (is_dead(philo) == true)
		return ;
	pthread_mutex_lock(&philo->shared->death_mutex);
	philo->shared->death_flag = true;
	pthread_mutex_unlock(&philo->shared->death_mutex);
	printf("%ld %d has died\n", gettime_in_ms(), philo->id);
}
