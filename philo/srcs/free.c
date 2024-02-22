/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:18:12 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/22 15:50:19 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
}

void	free_all(t_info *info, t_philo *philo)
{
	if (info)
	{
		ft_free(info->threads);
		ft_free(info->is_full_mutex);
		ft_free(info->time_mutex);
		ft_free(info->forks);
		ft_free(info);
	}
	ft_free(philo);
}

int	puterror_and_free(const char *fmt, t_info *info, t_philo *philos)
{
	put_error(fmt, ERROR);
	free_all(info, philos);
	return (ERROR);
}
