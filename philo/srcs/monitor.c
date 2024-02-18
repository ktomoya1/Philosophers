/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:54:27 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/18 16:04:09 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(t_info *info, t_philo *philos)
{
	int	i;

	i = 0;
	ft_usleep(info->time_to_die);
	while (true)
	{
		if (is_dead(&philos[i]) == true)
		{
			die(&philos[i]);
			return ;
		}
		if (i == info->num_of_philos - 1)
			i = 0;
		i++;
	}
}
