/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_a_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:33:55 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/28 08:29:11 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_a_fork(t_philo *philo)
{
	if (philo->forks_in_hand == 0)
		pthread_mutex_lock(philo->left_fork);
	else if (philo->forks_in_hand == 1)
		pthread_mutex_lock(philo->right_fork);
	philo->forks_in_hand++;
	print_message(philo, "has taken a fork");
}
