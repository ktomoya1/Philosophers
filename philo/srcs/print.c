/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:14:53 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/18 15:58:52 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(const char *msg, t_philo *philo)
{
	pthread_mutex_lock(&philo->info->print_mutex);
	pthread_mutex_lock(&philo->info->someone_dead_mutex);
	if (philo->info->someone_dead == false)
		printf("%d %d %s\n", get_time() - philo->info->start_time
				, philo->id, msg);
	pthread_mutex_unlock(&philo->info->someone_dead_mutex);
	pthread_mutex_unlock(&philo->info->print_mutex);
}

int	put_error(const char *format, int error_code)
{
	write(STDERR_FILENO, format, ft_strlen(format));
	write(STDERR_FILENO, "\n", 1);
	return (error_code);
}
