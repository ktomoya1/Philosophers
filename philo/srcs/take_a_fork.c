/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_a_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:33:55 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/16 20:06:55 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_a_fork(t_philo *philo, int fork_id)
{
	pthread_mutex_lock(&philo->shared->forks[fork_id]);
	philo->forks_in_hand++;
	if (philo->shared->is_dead == false)
		printf("%ld %d has taken a %d fork\n", gettime_in_ms(), philo->id, fork_id);
}
