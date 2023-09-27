/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:12:03 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/27 23:24:53 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/sl_errors.h"
#include "../inc/so_long.h"

void	sl_error_handler(char *status)
{
	ft_printf("Error, --- %s --- \n", status);
	exit(1);
}
