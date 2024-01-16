/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:58:36 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/16 14:19:51 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	if (philo->forks_in_hand != 2)
		return ;
//	if (philo->shared->is_dead == true)
//		return ;
//	printf("%ld %d is eating\n", gettime_in_ms(), philo->id);
	print_message(philo, "is eating");
	usleep(philo->time_to_eat);
}
