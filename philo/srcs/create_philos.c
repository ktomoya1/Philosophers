/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:10:58 by ktomoya           #+#    #+#             */
/*   Updated: 2023/12/26 17:55:35 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philos(pthread_t philos[], int n_philos)
{
	int	i;
	int	err;

	i = 0;
	while (i < n_philos)
	{
		err = pthread_create(&philos[i], NULL, think, &i);
		usleep(20);
		if (err != SUCCESS)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
