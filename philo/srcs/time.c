/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:29:52 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/30 12:48:47 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

useconds_t	get_cur_time(void)
{
	useconds_t		ms_time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	ms_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms_time);
}

void	ft_msleep(int time)
{
	useconds_t	end_time;

	end_time = get_cur_time() + time;
	while (end_time > get_cur_time())
	{
		usleep((end_time - get_cur_time()) / 4 * 1000);
	}
}
