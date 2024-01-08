/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:02:08 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/08 16:21:15 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	setup_philo(t_philo philos[], char *argv[])
{
	int			max_philo;
	useconds_t	time_to_die;
	int			i;

	max_philo = ft_atoi(argv[1]);
	time_to_die = ft_atoi(argv[2]);
	i = 0;
	while (i < max_philo)
	{
		philos[i].id = i + 1;
		philos[i].time_to_die = time_to_die;
		i++;
	}
	return (SUCCESS);
}
