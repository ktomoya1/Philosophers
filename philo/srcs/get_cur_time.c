/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cur_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:54:57 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/28 18:58:15 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_cur_time(void)
{
	long			ms_time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	ms_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms_time);
}
