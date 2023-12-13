/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:00:28 by ktomoya           #+#    #+#             */
/*   Updated: 2023/11/24 12:48:42 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

pthread_t	ntid;

// プロセスIDとスレッドIDの表示を行う。
void	printids(const char *s)
{
	pid_t		pid;
	pthread_t	tid;

	pid = getpid();
	// pthread_self()関数は自身のスレッドIDを取得する
	tid = pthread_self();
	// %luは符号なし倍精度整数を10進数で出力、%lxは倍精度整数を16進数で出力する
	printf("%s pid %lu tid %lu (0x%lx)\n", s, (unsigned long)pid, (unsigned long)tid, (unsigned long)tid);
}

// 新しいスレッドのIDを表示する関数。pthread_create関数を呼び出すとこの関数も呼び出される。
void	*thr_fn(void *arg)
{
	(void)arg;
	printids("new thread: ");
	return (NULL);
}

//int	main(void)
//{
//	int	err;
//
//	err = pthread_create(&ntid, NULL, thr_fn, NULL);
//	if (err != 0)
//	{
//		dprintf(STDERR_FILENO, "can't create thread");
//		exit(0);
//	}
//	printids("main thread");
//	sleep(1);
//	exit(0);
//}
