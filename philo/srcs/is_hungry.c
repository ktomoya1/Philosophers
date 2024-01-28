/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hungry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:27:52 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/28 18:58:47 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_hungry(t_philo *philo)
{
	useconds_t	elapsed_time;

	elapsed_time = get_cur_time() - philo->start_time;
	if (elapsed_time > philo->time_to_die)
		return (true);
	return (false);
}
