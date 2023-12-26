/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:02:32 by ktomoya           #+#    #+#             */
/*   Updated: 2023/12/26 17:54:26 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*think(void *arg)
{
	int				philo_id;

	philo_id = *(int *)arg;
	printf("%ld %d is thinking\n", gettime_in_ms(), philo_id + 1);
	return ((void *)0);
}