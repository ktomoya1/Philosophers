/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:01:13 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/17 07:55:36 by ktomoya          ###   ########.fr       */
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

int	check_input(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
		return (put_error("Error: Invalid argument count", FAILURE));
	if (has_nondigits(argv[1]) == true || ft_atoi(argv[1]) <= 0
		|| ft_atoi(argv[1]) > INT_MAX || errno == ERANGE)
		return (put_error("Error: Invalid number of philosophers", FAILURE));
	if (has_nondigits(argv[2]) == true || ft_atoi(argv[2]) <= 0
		|| ft_atoi(argv[2]) > USLEEP_MAX || errno == ERANGE)
		return (put_error("Error: Invalid time to die", FAILURE));
	if (has_nondigits(argv[3]) == true || ft_atoi(argv[3]) <= 0
		|| ft_atoi(argv[3]) > USLEEP_MAX || errno == ERANGE)
		return (put_error("Error: Invalid time to eat", FAILURE));
	if (has_nondigits(argv[4]) == true || ft_atoi(argv[4]) <= 0
		|| ft_atoi(argv[4]) > USLEEP_MAX || errno == ERANGE)
		return (put_error("Error: Invalid time to sleep", FAILURE));
	if (argc == 6 && (has_nondigits(argv[5]) == true
			|| ft_atoi(argv[5]) <= 0 || errno == ERANGE))
		return (put_error("Error: Invalid minimum meal number", FAILURE));
	return (SUCCESS);
}
