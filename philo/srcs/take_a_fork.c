/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_a_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:33:55 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/28 18:39:26 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_a_fork(t_philo *philo)
{
	if (philo->fork_count == 0)
		pthread_mutex_lock(philo->left_fork);
	else if (philo->fork_count == 1)
		pthread_mutex_lock(philo->right_fork);
	philo->fork_count++;
	print_message(philo, "has taken a fork");
}
