/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_vac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:32:04 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/19 21:57:51 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pf_putnchar(char c, int n, int fd)
{
	int	counter;

	if (n <= 0)
		return (0);
	counter = 0;
	while (n--)
		counter += write(fd, &c, 1);
	return (counter);
}

int	ft_pf_vac(t_flags *flags, const char c)
{
	int	counter;

	counter = 0;
	if (flags->minus)
	{
		counter += ft_pf_putnchar(c, 1, flags->fd);
		counter += ft_pf_putnchar(' ', flags->minus - 1, flags->fd);
	}
	else if (flags->numb)
	{
		counter += ft_pf_putnchar(' ', flags->numb - 1, flags->fd);
		counter += ft_pf_putnchar(c, 1, flags->fd);
	}
	else if (flags->zero)
	{
		counter += ft_pf_putnchar(' ', flags->zero - 1, flags->fd);
		counter += ft_pf_putnchar(c, 1, flags->fd);
	}
	else
		counter += ft_pf_putnchar(c, 1, flags->fd);
	return (counter);
}
