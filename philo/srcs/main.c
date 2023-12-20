/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:45:21 by ktomoya           #+#    #+#             */
/*   Updated: 2023/12/08 13:55:16 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 哲学者に考える機能をつける
int	main(int argc, char *argv[])
{
//	t_philo	philos[PHILO_MAXSIZE];
	pthread_t	philos[PHILO_MAXSIZE];

	errno = 0;
	// 入力チェック
	if (check_input(argc, argv) != SUCCESS)
		return (FAILURE);
	//　哲学者（スレッド）を作る
	
	//　哲学者（スレッド）を初期化する
	// init_philos(philos, PHILO_MAXSIZE);
	printf("philos[PHILO_MAXSIZE].id: %d\n", philos[PHILO_MAXSIZE - 1].id);
	//　哲学者に値を設定する
	return (SUCCESS);
}
