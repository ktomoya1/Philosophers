/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:06:10 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/18 15:16:55 by ktomoya          ###   ########.fr       */
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

void	ft_usleep(useconds_t time)
{
	useconds_t	end_time;

	end_time = get_time() + time;
	while (end_time > get_time())
	{
		usleep((end_time - get_time()) / 4 * 1000);
	}
}
