/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_alive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:48:01 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/29 14:50:44 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_alive(t_philo *philo)
{
	bool	is_alive;

	pthread_mutex_lock(&philo->shared->death_mutex);
	if (philo->shared->death_flag == false)
		is_alive = true;
	else
		is_alive = false;
	pthread_mutex_unlock(&philo->shared->death_mutex);
	return (is_alive);
}
