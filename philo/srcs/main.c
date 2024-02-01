/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:45:21 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/01 10:40:34 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philo		philos[PHILO_MAX];
	t_config	*shared;
	pthread_t	threads[PHILO_MAX];

	if (validate_input(argc, argv) != SUCCESS)
		return (FAILURE);
	shared = setup_shared_data(argc, ft_atoi(argv[1]));
	if (shared == NULL)
		return (ERROR);
	init_philo(philos, argv, shared);
	if (create_thread(threads, philos) == ERROR)
		return (FAILURE);
	monitor(philos);
	wait_thread(threads);
	free(shared);
}

t_config	*setup_shared_data(int argc, int num_of_philos)
{
	t_config	*shared;
	int			i;

	shared = (t_config *)malloc(sizeof(t_config));
	if (shared == NULL)
		return (NULL);
	shared->num_of_philos = num_of_philos;
	shared->death_flag = false;
	if (pthread_mutex_init(&shared->death_mutex, NULL) != SUCCESS)
		return (free_ret_nul(shared));
	if (pthread_mutex_init(&shared->print_mutex, NULL) != SUCCESS)
		return (free_ret_nul(shared));
	if (pthread_mutex_init(&shared->time_mutex, NULL) != SUCCESS)
		return (free_ret_nul(shared));
	i = 0;
	while (i < num_of_philos)
	{
		if (pthread_mutex_init(&shared->forks[i], NULL) != SUCCESS)
			return (free_ret_nul(shared));
		i++;
	}
	shared->condition = is_alive;
	if (argc == 6)
		shared->condition = is_alive_and_eating;
	return (shared);
}

void	init_philo(t_philo philos[], char *argv[], t_config *shared)
{
	int			i;

	i = 0;
	while (i < shared->num_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].fork_count = 0;
		philos[i].right_fork = NULL;
		philos[i].left_fork = NULL;
		philos[i].meal_count = 0;
		philos[i].start_time = 0;
		philos[i].time_to_die = ft_atoi(argv[2]);
		philos[i].time_to_eat = ft_atoi(argv[3]);
		philos[i].time_to_sleep = ft_atoi(argv[4]);
		if (argv[5] == NULL)
			philos[i].minimum_meal_count = 0;
		else
			philos[i].minimum_meal_count = ft_atoi(argv[5]);
		philos[i].shared = shared;
		i++;
	}
}

// __attribute__((destructor))
// static void	destructor(void)
// {
// 	system("leaks -q philo");
// }
