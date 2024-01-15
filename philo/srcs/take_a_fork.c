/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_a_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:17:51 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/15 18:27:40 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_a_fork(t_philo *philo)
{
	int	fork_id;

	if (philo->forks_in_hand == 0)
		fork_id = philo->id - 1;
	else if (philo->forks_in_hand == 1 && philo->id == 1)
		fork_id = philo->shared->num_of_philos - 1;
	else
		fork_id = philo->id - 2;
	if (philo->shared->fork[fork_id] == false)
		return ;
	philo->shared->fork[fork_id] = false;
	philo->forks_in_hand++;
	if (philo->shared->is_dead == false)
		printf("%ld %d has taken a %d fork\n", gettime_in_ms(), philo->id, fork_id);
}
