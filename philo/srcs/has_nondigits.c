/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_nondigits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:05:53 by ktomoya           #+#    #+#             */
/*   Updated: 2024/01/08 14:11:47 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	has_nondigits(const char *s)
{
	while (*s != '\0')
	{
		if (!ft_isdigit(*s))
			return (true);
		s++;
	}
	return (true);
}
