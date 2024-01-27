/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:36:25 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/28 06:51:56 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_input(int argc, char *argv[])
{
	if (argc != 6)
		return (put_err_ret(FAILURE, "Error: Invalid argument count"));
	// check number_of_philosophers
	if (ft_atoi(argv[1]) <= 0  || ft_atoi(argv[1]) > PHILO_MAX || errno == ERANGE)
		return (put_err_ret(FAILURE, "Error: Invalid number of philosophers"));
	// check time_to_die
	if (ft_atoi(argv[2]) <= 0  || ft_atoi(argv[2]) > USLEEP_MAX || errno == ERANGE)
		return (put_err_ret(FAILURE, "Error: Invalid time to die"));
	// check time_to_eat
	if (ft_atoi(argv[3]) <= 0  || ft_atoi(argv[3]) > USLEEP_MAX || errno == ERANGE)
		return (put_err_ret(FAILURE, "Error: Invalid time to eat"));
	// check time_to_sleep
	if (ft_atoi(argv[4]) <= 0  || ft_atoi(argv[4]) > USLEEP_MAX || errno == ERANGE)
		return (put_err_ret(FAILURE, "Error: Invalid time to sleep"));
	// check minimum_meal_count
	if (ft_atoi(argv[5]) <= 0  || errno == ERANGE)
		return (put_err_ret(FAILURE, "Error: Invalid minimum meal number"));
	return (SUCCESS);
}
