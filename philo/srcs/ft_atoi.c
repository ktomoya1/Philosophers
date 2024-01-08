/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:46:27 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/08 15:25:35 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_overflow(int num, int num_to_add)
{
	long int	max_div;
	long int	max_mod;

	max_div = LONG_MAX / 10;
	max_mod = LONG_MAX % 10;
	if (num > max_div)
		return (true);
	if (max_div == num && max_mod < num_to_add)
		return (true);
	return (false);
}

static int	setup_sign(const char *s)
{
	int	sign;

	sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	return (sign);
}

int	ft_atoi(const char *s)
{
	int		num;
	int		sign;

	errno = 0;
	num = 0;
	while (ft_isspace(*s))
		s++;
	sign = setup_sign(s);
	while (ft_isdigit(*s))
	{
		if (is_overflow(num, *s - '0') == true)
		{
			errno = ERANGE;
			if (sign == 1)
				return ((int)LONG_MAX);
			if (sign == -1)
				return ((int)LONG_MIN);
		}
		num = num * 10 + (*s - '0');
		s++;
	}
	return (sign * num);
}
