/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:45:21 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/29 18:36:24 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philo			philos[PHILO_MAX];
	t_shared_data	*shared;
	pthread_t		threads[PHILO_MAX];

	if (validate_input(argc, argv) != SUCCESS)
		return (FAILURE);
	shared = setup_shared_data(argc, ft_atoi(argv[1]));
	if (shared == NULL)
		return (ERROR);
	init_philo(philos, argv, shared);
	if (create_thread(threads, philos) == ERROR)
		return (FAILURE);
	wait_thread(threads);
	free(shared);
}

t_shared_data	*setup_shared_data(int argc, int num_of_philos)
{
	t_shared_data	*shared;
	int				i;

	shared = (t_shared_data *)malloc(sizeof(t_shared_data));
	if (shared == NULL)
		return (NULL);
	shared->num_of_philos = num_of_philos;
	shared->death_flag = false;
	if (pthread_mutex_init(&shared->death_mutex, NULL) != SUCCESS)
		return (free_ret_nul(shared));
	i = 0;
	while (i < num_of_philos)
	{
		if (pthread_mutex_init(&shared->forks[i], NULL) != SUCCESS)
			return (free_ret_nul(shared));
		i++;
	}
	if (argc == 5)
		shared->condition = is_alive;
	else
		shared->condition = is_alive_and_eating;
	return (shared);
}

void	init_philo(t_philo philos[], char *argv[], t_shared_data *shared)
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
