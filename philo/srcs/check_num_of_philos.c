/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num_of_philos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:55:23 by ktomoya           #+#    #+#             */
/*   Updated: 2023/12/26 17:37:32 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_num_of_philos(int *n_philos, const char *s)
{
	// atoiチェック、数字以外の文字が入っていたらエラーを返す
	*n_philos = nonnegative_atoi(s);
	if (*n_philos == ERROR && errno == EINVAL)
		return (put_err_ret(ERROR, "Error: Contains non-numeric characters"));
	// int型のオーバーフローチェック
	else if (errno == ERANGE)
		return (put_err_ret(ERROR, "Error: Overflow detected for integer"));
	if (*n_philos == 0 || *n_philos > PHILO_MAXSIZE)
		return (put_err_ret(ERROR, "Error: Invalid number of philosophers"));
	return (SUCCESS);
}
