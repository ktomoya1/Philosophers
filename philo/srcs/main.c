/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:45:21 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/15 17:18:06 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 哲学者一人が左右のフォークをとるプログラム
int	main(int argc, char *argv[])
{
	t_philo			philos[PHILO_MAX];
	t_shared_data	*shared;
	pthread_t		threads[PHILO_MAX];

	if (validate_input(argc, argv) != SUCCESS)
		return (FAILURE);
	shared = setup_shared_data(ft_atoi(argv[1]));
	// 共有リソースの初期化
	if (shared == NULL)
		return (ERROR);
	// 哲学者の構造体に値を設定する
	init_philo(philos, argv, shared);
	// スレッドを作成する
	if (create_thread(threads, philos) == ERROR)
		return (FAILURE);
	// スレッドの終了を待つ
	wait_thread(threads);
	// free
	free(shared);
}
