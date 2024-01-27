/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fall_asleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:39:56 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/28 06:54:28 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fall_asleep(t_philo *philo)
{
	if (has_eaten(philo) == true)
		return ;
	print_message(philo, "is sleeping");
	usleep(philo->time_to_sleep);
}
