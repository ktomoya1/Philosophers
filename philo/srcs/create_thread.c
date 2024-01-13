/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:10:58 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/13 17:50:41 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_thread(pthread_t threads[], t_philo philos[], int philo_count)
{
	int	status;
	int	i;

	i = 0;
	while (i < philo_count)
	{
		status = pthread_create(&threads[i], NULL, philo_routine, (void *)&philos[i]);
		if (status != SUCCESS)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
