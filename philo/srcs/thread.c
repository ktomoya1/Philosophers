/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:22:07 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/16 08:48:29 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_thread(pthread_t threads[], t_philo philos[])
{
	int	status;
	int	i;

	i = 0;
	philos[0].shared->program_start = get_cur_time()
		+ philos[0].shared->num_of_philos * 2;
	while (i < philos[0].shared->num_of_philos)
	{
		status = pthread_create(&threads[i], NULL, routine, (void *)&philos[i]);
		if (status != SUCCESS)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	wait_thread(pthread_t threads[], int num_of_philos)
{
	int	i;

	i = 0;
	while (i < num_of_philos)
	{
		printf("i: %d\n", i);
		pthread_join(threads[i], NULL);
		i++;
	}
	return (SUCCESS);
}
