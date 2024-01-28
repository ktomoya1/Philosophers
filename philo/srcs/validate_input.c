/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:36:25 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/28 09:33:56 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_input(int argc, char *argv[])
{
	if (argc != 6)
		return (put_err_ret(FAILURE, "Error: Invalid argument count"));
	if (ft_atoi(argv[1]) <= 0  || ft_atoi(argv[1]) > PHILO_MAX || errno == ERANGE)
		return (put_err_ret(FAILURE, "Error: Invalid number of philosophers"));
	if (ft_atoi(argv[2]) <= 0  || ft_atoi(argv[2]) > USLEEP_MAX || errno == ERANGE)
		return (put_err_ret(FAILURE, "Error: Invalid time to die"));
	if (ft_atoi(argv[3]) <= 0  || ft_atoi(argv[3]) > USLEEP_MAX || errno == ERANGE)
		return (put_err_ret(FAILURE, "Error: Invalid time to eat"));
	if (ft_atoi(argv[4]) <= 0  || ft_atoi(argv[4]) > USLEEP_MAX || errno == ERANGE)
		return (put_err_ret(FAILURE, "Error: Invalid time to sleep"));
	if (ft_atoi(argv[5]) <= 0  || errno == ERANGE)
		return (put_err_ret(FAILURE, "Error: Invalid minimum meal number"));
	return (SUCCESS);
}
