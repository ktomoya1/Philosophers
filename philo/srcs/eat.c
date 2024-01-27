/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:58:36 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/28 06:46:11 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	if (philo->forks_in_hand != 2)
		return ;
	if (is_hungry(philo) == true)
	{
		die(philo);
		return ;
	}
	philo->meal_count++;
	print_message(philo, "is eating");
	usleep(philo->time_to_eat);
}
