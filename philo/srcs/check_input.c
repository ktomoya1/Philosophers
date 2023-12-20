/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:03:12 by ktomoya           #+#    #+#             */
/*   Updated: 2023/12/08 15:25:04 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 入力チェック関数
int	check_input(int argc, char *argv[])
{
	int	n_philos;

	// 引数の数を確認する
	if (argc != 2)
		return (put_err_ret(FAILURE, "Error: Invalid number of arguments"));
	// atoiチェック、数字以外の文字が入っていたらエラーを返す
	n_philos = nonnegative_atoi(argv[1]);
	if (n_philos == ERROR && errno == EINVAL)
		return (put_err_ret(FAILURE, "Error: Contains non-numeric characters"));
	// int型のオーバーフローチェック
	else if (errno == ERANGE)
		return (put_err_ret(FAILURE, "Error: Overflow detected for integer"));
	// スレッドを回数分作れるか？
//	if (validate_pthread_count(n_philos) == ERROR)
//		return (put_err_ret(FAILURE, "Error: Failed to create thread"));
	return (SUCCESS);
}
