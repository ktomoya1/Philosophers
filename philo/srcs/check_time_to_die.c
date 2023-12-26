/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_time_to_die.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:41:52 by ktomoya           #+#    #+#             */
/*   Updated: 2023/12/26 19:59:21 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_time_to_die(useconds_t *time_to_die, const char *s)
{
	int	time_to_die_int;

	// atoiチェック
	time_to_die_int = nonnegative_atoi(s);
	if (time_to_die_int == ERROR && errno == EINVAL)
		return (put_err_ret(ERROR, "Error: Contains non-numeric characters"));
	else if (errno == ERANGE)
		return (put_err_ret(ERROR, "Error: Overflow detected for integer"));
	// 0 ~ 1000000の範囲内か？
	if (time_to_die_int == 0 || time_to_die_int > USLEEP_MAX)
		return (put_err_ret(ERROR, "Error: Invalid value for seconds"));
	*time_to_die = (useconds_t)time_to_die_int;
	return (SUCCESS);
}
