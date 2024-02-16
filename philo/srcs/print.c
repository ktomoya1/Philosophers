/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:14:53 by ktomoya           #+#    #+#             */
/*   Updated: 2024/02/16 15:15:03 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	put_error(const char *format, int error_code)
{
	write(STDERR_FILENO, format, ft_strlen(format));
	write(STDERR_FILENO, "\n", 1);
	return (error_code);
}
