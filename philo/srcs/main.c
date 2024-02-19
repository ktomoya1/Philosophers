/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:41:38 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/19 12:11:00 by ktomoya          ###   ########.fr       */
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
		return (ERROR);
	if (init_mutex(info) != SUCCESS)
		return (ERROR);
	if (init_philos(&philos, info) != SUCCESS)
		return (ERROR);
	if (run_threads(info, philos) != SUCCESS)
		return (ERROR);
	destroy_and_free(NULL, info, philos);
	return (SUCCESS);
}

//__attribute__((destructor))
//static void	destructor(void)
//{
//	system("leaks -q philo");
//}
