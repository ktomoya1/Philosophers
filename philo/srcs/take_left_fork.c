/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_left_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:17:51 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/13 18:29:47 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_left_fork(t_philo *philo)
{
	if (philo->shared->is_dead == true)
		return ;
	if (philo->shared->fork[philo->id - 1] == false)
		return ;
	philo->shared->fork[philo->id - 1] = false;
	printf("%ld %d has taken a fork\n", gettime_in_ms(), philo->id);
}
