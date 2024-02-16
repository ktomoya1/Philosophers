/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:29:49 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/16 15:23:09 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	//t_info	*info;
	//t_philo	*philo;

	if (check_input(argc, argv) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}
