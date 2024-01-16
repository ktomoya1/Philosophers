/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_fork_id.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:12:17 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/16 21:33:20 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	assign_fork_id(t_philo *philo)
{
	int	fork_id;

	if (philo->forks_in_hand == 0)
		fork_id = philo->id - 1;
	else if (philo->forks_in_hand == 1 && philo->id == 1)
		fork_id = philo->shared->num_of_philos - 1;
	else
		fork_id = philo->id - 2;
	if (philo->forks_in_hand == 0)
		philo->left_fork = &philo->shared->forks[fork_id];
	if (philo->forks_in_hand == 1)
		philo->right_fork = &philo->shared->forks[fork_id];
	return (fork_id);
}
