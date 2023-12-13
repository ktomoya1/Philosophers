/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:36:54 by ktomoya           #+#    #+#             */
/*   Updated: 2023/12/08 09:44:32 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_error(const char *format)
{
	write(STDERR_FILENO, format, ft_strlen(format));
	write(STDERR_FILENO, "\n", 1);
}
