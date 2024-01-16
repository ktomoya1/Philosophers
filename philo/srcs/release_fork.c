/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:20:09 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/16 21:10:12 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	release_fork(t_philo *philo)
{
	philo->forks_in_hand = 0;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}
