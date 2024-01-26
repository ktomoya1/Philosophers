/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:17:51 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/17 19:41:29 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	int	fork_id;

	philo->start_time = gettime_in_ms();
	fork_id = assign_fork_id(philo);
	take_a_fork(philo, fork_id);
	fork_id = assign_fork_id(philo);
	take_a_fork(philo, fork_id);
}
