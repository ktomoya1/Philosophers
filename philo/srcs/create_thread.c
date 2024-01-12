/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:10:58 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/10 18:58:24 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_thread(pthread_t threads[], t_philo philos[], int philo_count)
{
	int	err;
	int	i;

	i = 0;
	while (i < philo_count)
	{
		err = pthread_create(&threads[i], NULL, think, (void *)&philos[i]);
		if (err != SUCCESS)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
