/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:01:13 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/27 12:37:50 by ktomoya          ###   ########.fr       */
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
		return (print_usage("Error: Invalid argument count", FAILURE));
	if (has_nondigits(argv[1]) == true || ft_atoi(argv[1]) <= 0
		|| ft_atoi(argv[1]) > PHILO_MAX || errno == ERANGE)
		return (print_usage("Error: Invalid number_of_philosophers", FAILURE));
	if (has_nondigits(argv[2]) == true || ft_atoi(argv[2]) <= 0
		|| ft_atoi(argv[2]) > USLEEP_MAX || errno == ERANGE)
		return (print_usage("Error: Invalid time_to_die", FAILURE));
	if (has_nondigits(argv[3]) == true || ft_atoi(argv[3]) <= 0
		|| ft_atoi(argv[3]) > USLEEP_MAX || errno == ERANGE)
		return (print_usage("Error: Invalid time_to_eat", FAILURE));
	if (has_nondigits(argv[4]) == true || ft_atoi(argv[4]) <= 0
		|| ft_atoi(argv[4]) > USLEEP_MAX || errno == ERANGE)
		return (print_usage("Error: Invalid time_to_sleep", FAILURE));
	if (argc == 6 && (has_nondigits(argv[5]) == true
			|| ft_atoi(argv[5]) <= 0 || errno == ERANGE))
		return (print_usage("Error: Invalid minimum_meal_count", FAILURE));
	return (SUCCESS);
}
