/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_shared_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:19:56 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/13 17:39:24 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	setup_shared_data(t_shared_data **shared, int size)
{
	*shared = (t_shared_data *)malloc(sizeof(t_shared_data));
	if (*shared == NULL)
		return (ERROR);
	shared[0]->is_dead = false;
	memset(shared[0]->fork, true, sizeof(bool) * size);
	return (SUCCESS);
}
