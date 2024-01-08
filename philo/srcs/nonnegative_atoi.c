/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nonnegative_atoi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:13:27 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/06 19:48:13 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_int_overflow(int num, int num_to_add)
{
	int max_div;
	int	max_mod;

	max_div = INT_MAX / 10;
	max_mod = INT_MAX % 10;
	if (num > max_div)
		return (1);
	if (max_div == num && max_mod < num_to_add)
		return (1);
	return (0);
}

int	nonnegative_atoi(const char *s)
{
	int	num;

	errno = 0;
	num = 0;
	while (ft_isspace(*s))
		s++;
	if (!ft_isdigit(*s))
		return (set_errno_ret(ERROR, EINVAL));
	while (ft_isdigit(*s))
	{
		if (is_int_overflow(num, *s - '0'))
			return (set_errno_ret(ERROR, ERANGE));
		num = num * 10 + (*s - '0');
		s++;
	}
	while (ft_isspace(*s))
		s++;
	if (*s != '\0')
		return (set_errno_ret(ERROR, EINVAL));
	return (num);
}
