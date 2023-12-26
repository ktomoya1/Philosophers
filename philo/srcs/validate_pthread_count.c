/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_pthread_count.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:31:46 by ktomoya           #+#    #+#             */
/*   Updated: 2023/12/13 15:49:20 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_pthread_count(int count)
{
	pthread_t	threads[count];
	int			ret;
	int			i;

	i = 0;
	while (i < count)
	{
		ret = pthread_create(&threads[i], NULL, thread_func, NULL);
		if (ret != SUCCESS)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
