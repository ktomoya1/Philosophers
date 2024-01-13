/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:45:21 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/13 17:40:59 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 哲学者一人が左のフォークをとるプログラム
int	main(int argc, char *argv[])
{
	t_philo			philos[PHILO_MAX];
	t_shared_data	*shared;
	pthread_t		threads[PHILO_MAX];

	if (validate_input(argc, argv) != SUCCESS)
		return (FAILURE);
	shared = NULL;
	// 共有リソースの初期化
	if (setup_shared_data(&shared, PHILO_MAX) == ERROR)
		return (ERROR);
	// 哲学者の構造体に値を設定する
	init_philo(philos, argv, shared);
	// スレッドを作成する
	if (create_thread(threads, philos, ft_atoi(argv[1])) == ERROR)
		return (FAILURE);
	// スレッドの終了を待つ
	wait_thread(threads);
	// free
	free(shared);
}
