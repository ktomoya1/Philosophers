/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:13:38 by ktomoya           #+#    #+#             */
/*   Updated: 2023/12/25 15:40:40 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_philos(pthread_t philos[])
{
	int	err;
	int	i;

	i = 0;
	while (philos[i] != NULL)
	{
		err = pthread_join(philos[i], NULL);
		if (err != SUCCESS)
			return (put_err_ret(ERROR, "can't join with thread"));
		i++;
	}
	return (SUCCESS);
}
