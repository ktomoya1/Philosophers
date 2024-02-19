/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:18:12 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/19 12:55:26 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_info *info, t_philo *philo)
{
	if (info)
	{
		if (info->threads)
			free(info->threads);
		if (info->is_full_mutex)
			free(info->is_full_mutex);
		if (info->time_mutex)
			free(info->time_mutex);
		if (info->forks)
			free(info->forks);
		free(info);
		info = NULL;
	}
	if (philo)
	{
		free(philo);
		philo = NULL;
	}
}

int	puterror_and_free(const char *fmt, t_info *info, t_philo *philos)
{
	put_error(fmt, ERROR);
	free_all(info, philos);
	return (ERROR);
}

int	destroy_and_free(const char *format, t_info *info, t_philo *philos)
{
	if (format != NULL)
		put_error(format, ERROR);
	destroy_mutex(info);
	free_all(info, philos);
	return (ERROR);
}
