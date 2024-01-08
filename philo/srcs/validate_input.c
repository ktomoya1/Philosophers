/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:36:25 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/08 15:28:36 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// idとtime_to_dieのチェック
int	validate_input(int argc, char *argv[])
{
	if (argc != 3)
		return (put_err_ret(FAILURE, "Error: Invalid argument count"));
	// check number_of_philosophers
	if (ft_atoi(argv[1]) <= 0  || ft_atoi(argv[1]) > PHILO_MAX || errno == ERANGE)
		return (put_err_ret(FAILURE, "Error: Invalid number of philosophers"));
	// check time_to_die
	if (ft_atoi(argv[1]) <= 0  || ft_atoi(argv[1]) > USLEEP_MAX || errno == ERANGE)
		return (put_err_ret(FAILURE, "Error: Invalid time to die"));
	return (SUCCESS);
}
