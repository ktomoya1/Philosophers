/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:08:56 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/27 15:27:26 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *philo, const char *msg)
{
	if (is_dead(philo) == true)
		return ;
	printf("%ld %d %s\n", gettime_in_ms(), philo->id, msg);
}
