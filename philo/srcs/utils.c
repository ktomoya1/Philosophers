/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:49:35 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/19 08:43:31 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	puterror_and_free(const char *fmt, t_info *info, t_philo *philos)
{
	put_error(fmt, ERROR);
	free_all(info, philos);
	return (ERROR);
}

int	destroy_and_free(const char *format, t_info *info, t_philo *philos)
{
	put_error(format, ERROR);
	destroy_mutex(info);
	free_all(info, philos);
	return (ERROR);
}
