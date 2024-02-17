/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:41:38 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/17 09:40:58 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_info	*info;
	t_philo	*philos;

	if (check_input(argc, argv) != SUCCESS)
		return (FAILURE);
	if (init_info(&info, argc, argv) != SUCCESS)
		return (FAILURE);
	if (init_mutex(info) != SUCCESS)
		return (FAILURE);
	if (init_philos(&philos, info) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}
