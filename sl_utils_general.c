/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils_general.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:01:21 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/21 17:41:22 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	sl_contains(const char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (1);
}

int	sl_endwith(char *str, char *end)
{
	int	sstr;
	int	send;
	int	diff;

	sstr = ft_strlen(str);
	send = ft_strlen(end);
	if (sstr < send)
		return (0);
	diff = sstr - send;
	while (diff--)
		str++;
	while (*str)
	{
		if (*str != *end)
			return (0);
		str++;
		end++;
	}
	return (1);
}
