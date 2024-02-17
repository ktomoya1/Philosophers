/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:49:35 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/17 08:53:11 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	puterror_and_free(const char *format, t_info *info, t_philo *philo)
{
	put_error(format, ERROR);
	free_all(info, philo);
	return (ERROR);
}
