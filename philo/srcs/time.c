/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:04:05 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/15 14:44:28 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

useconds_t	get_cur_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(useconds_t time)
{
	useconds_t	end_time;

	end_time = get_cur_time() + time;
	while (end_time > get_cur_time())
	{
		usleep((end_time - get_cur_time()) / 4 * 1000);
	}
}
