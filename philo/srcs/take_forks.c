/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:17:51 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/28 18:58:53 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	philo->start_time = get_cur_time();
	assign_fork_id(philo);
	take_a_fork(philo);
	assign_fork_id(philo);
	take_a_fork(philo);
}
