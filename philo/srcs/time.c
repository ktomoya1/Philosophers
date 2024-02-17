/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:06:10 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/17 11:11:44 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

useconds_t	get_time(void)
{
	struct timeval	ms_time;

	if (gettimeofday(&ms_time, NULL) == ERROR)
		return (put_error("gettimeofday error", FAILURE));
	return (ms_time.tv_sec * 1000 + ms_time.tv_usec / 1000);
}
