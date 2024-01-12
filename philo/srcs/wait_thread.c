/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:16:21 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/09 15:02:08 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	wait_thread(pthread_t threads[])
{
	int	i;

	i = 0;
	while (threads[i] != NULL)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	return (SUCCESS);
}
