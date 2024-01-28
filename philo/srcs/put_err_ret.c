/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_err_ret.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:13:41 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/28 17:31:38 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		put_err_ret(int error_code, const char *format)
{
	write(STDERR_FILENO, format, ft_strlen(format));
	write(STDERR_FILENO, "\n", 1);
	return (error_code);
}
