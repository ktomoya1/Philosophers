/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:08:56 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/29 17:28:27 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *philo, const char *msg)
{
	if (is_alive(philo) == false)
		return ;
	printf("%ld %d %s\n", get_cur_time(), philo->id, msg);
}
