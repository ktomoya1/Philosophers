/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:52:08 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/30 12:50:29 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *philo, const char *msg)
{
	if (is_alive(philo) == false)
		return ;
	printf("%d %d %s\n", get_cur_time() - philo->shared->program_start, philo->id, msg);
}

int	put_err_ret(int error_code, const char *format)
{
	write(STDERR_FILENO, format, ft_strlen(format));
	write(STDERR_FILENO, "\n", 1);
	return (error_code);
}
