/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:12:03 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/21 13:38:03 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/sl_errors.h"
#include "inc/so_long.h"

void	sl_error_handler(int status)
{
	ft_printf("EXIT, STATUS CODE --- %d ---", status); // enough for the first time
}
