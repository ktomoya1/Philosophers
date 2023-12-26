/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:45:21 by ktomoya           #+#    #+#             */
/*   Updated: 2023/12/26 19:14:33 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 哲学者に考える機能をつける
int	main(int argc, char *argv[])
{
	pthread_t		philos[PHILO_MAXSIZE];
	int				n_philos;
	useconds_t		tdie;

	errno = 0;
	if (argc != 3)
		return (put_err_ret(FAILURE, "Error: Invalid number of arguments"));
	if (check_num_of_philos(&n_philos, argv[1]) == ERROR)
		return (FAILURE);
	if (check_time_to_die(&tdie, argv[2]) == ERROR)
		return (FAILURE);
	//　哲学者を初期化する
	init_philos(philos, PHILO_MAXSIZE);
	//　哲学者（スレッド）を作る
	if (create_philos(philos, n_philos) == ERROR)
	{
		destroy_philos(philos);
		return (ERROR);
	}
	//　哲学者を終了する
	destroy_philos(philos);
	return (SUCCESS);
}
