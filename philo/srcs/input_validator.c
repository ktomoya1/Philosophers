/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:36:25 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/30 09:54:28 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	has_nondigits(const char *s)
{
	while (*s != '\0')
	{
		if (*s < '0' || *s > '9')
			return (true);
		s++;
	}
	return (false);
}

int	validate_input(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
		return (put_err_ret(FAILURE, "Error: Invalid argument count"));
	if (has_nondigits(argv[1]) == true || ft_atoi(argv[1]) <= 0
		|| ft_atoi(argv[1]) > PHILO_MAX || errno == ERANGE)
		return (put_err_ret(FAILURE, "Error: Invalid number of philosophers"));
	if (has_nondigits(argv[2]) == true || ft_atoi(argv[2]) <= 0
		|| ft_atoi(argv[2]) > USLEEP_MAX || errno == ERANGE)
		return (put_err_ret(FAILURE, "Error: Invalid time to die"));
	if (has_nondigits(argv[3]) == true || ft_atoi(argv[3]) <= 0
		|| ft_atoi(argv[3]) > USLEEP_MAX || errno == ERANGE)
		return (put_err_ret(FAILURE, "Error: Invalid time to eat"));
	if (has_nondigits(argv[4]) == true || ft_atoi(argv[4]) <= 0
		|| ft_atoi(argv[4]) > USLEEP_MAX || errno == ERANGE)
		return (put_err_ret(FAILURE, "Error: Invalid time to sleep"));
	if (argc == 6 && (has_nondigits(argv[5]) == true
			|| ft_atoi(argv[5]) <= 0 || errno == ERANGE))
		return (put_err_ret(FAILURE, "Error: Invalid minimum meal number"));
	return (SUCCESS);
}
