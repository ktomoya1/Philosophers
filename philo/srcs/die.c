/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:40:46 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/13 19:44:22 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	die(t_philo *philo)
{
	if (philo->shared->is_dead == true)
		return ;
	philo->shared->is_dead = true;
	printf("%ld %d died\n", gettime_in_ms(), philo->id);
}
