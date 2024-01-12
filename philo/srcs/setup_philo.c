/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:02:08 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/12 19:52:55 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	setup_philo(t_philo philos[], char *argv[], int philo_count)
{
	useconds_t	time_to_die;
	bool		*is_dead;
	int			i;

	time_to_die = ft_atoi(argv[2]);
	is_dead = (bool *)malloc(sizeof(bool));
	if (is_dead == NULL)
		return (ERROR);
	*is_dead = false;
	i = 0;
	while (i < philo_count)
	{
		philos[i].id = i + 1;
		philos[i].time_to_die = time_to_die;
		philos[i].is_dead = is_dead;
		i++;
	}
	return (SUCCESS);
}
