/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:02:58 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/27 15:09:26 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_dead(t_philo *philo)
{
	bool	is_dead;

	pthread_mutex_lock(&philo->shared->death_mutex);
	if (philo->shared->death_flag == true)
		is_dead = true;
	else
		is_dead = false;
	pthread_mutex_unlock(&philo->shared->death_mutex);
	return (is_dead);
}
