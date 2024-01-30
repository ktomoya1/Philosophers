/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:56:25 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/30 13:43:11 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

useconds_t	get_cur_time(void)
{
	useconds_t		ms_time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	ms_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms_time);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

static bool	is_overflow(int num, int num_to_add)
{
	long int	max_div;
	long int	max_mod;

	max_div = INT_MAX / 10;
	max_mod = INT_MAX % 10;
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
	while (('\t' <= *s && *s <= '\r') || *s == ' ')
		s++;
	sign = setup_sign(s);
	while ('0' <= *s && *s <= '9')
	{
		if (is_overflow(num, *s - '0') == true)
		{
			errno = ERANGE;
			if (sign == 1)
				return (INT_MAX);
			if (sign == -1)
				return (INT_MIN);
		}
		num = num * 10 + (*s - '0');
		s++;
	}
	return (sign * num);
}
