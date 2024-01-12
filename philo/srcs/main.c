/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:45:21 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/12 20:18:52 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 哲学者に餓死する機能をつける
int	main(int argc, char *argv[])
{
	t_philo		philos[PHILO_MAX];
	pthread_t	threads[PHILO_MAX];

	if (validate_input(argc, argv) != SUCCESS)
		return (FAILURE);
	// 哲学者の構造体に値を設定する
	if (setup_philo(philos, argv, ft_atoi(argv[1])) == ERROR)
		return (ERROR);
	// スレッドを作成する
	if (create_thread(threads, philos, ft_atoi(argv[1])) == ERROR)
		return (FAILURE);
	// スレッドの終了を待つ
	wait_thread(threads);
}
