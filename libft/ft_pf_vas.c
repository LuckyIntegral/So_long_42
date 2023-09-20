/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_vas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:52:56 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/19 21:59:55 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pf_putnstr(const char *str, int n, int fd)
{
	int	counter;

	counter = 0;
	while (n-- && *str)
	{
		counter += write(fd, str, 1);
		str++;
	}
	return (counter);
}

size_t	ft_pf_spec_str_len(int dot, const char *str)
{
	size_t	actual_len;

	actual_len = ft_tr(!str, ft_strlen("(null)"), ft_strlen(str));
	if (dot)
		return (ft_min_s(dot, actual_len));
	else
		return (actual_len);
}

int	ft_pf_vas(t_flags *flags, const char *str)
{
	size_t	l;
	int		counter;

	counter = 0;
	if (flags->dot == -1)
		return (counter);
	l = ft_pf_spec_str_len(flags->dot, str);
	if (flags->minus)
	{
		counter += ft_pf_putnstr(ft_tr_nul(str, "(null)", str), l, flags->fd);
		counter += ft_pf_putnchar(' ', flags->minus - l, flags->fd);
	}
	else if (flags->numb)
	{
		counter += ft_pf_putnchar(' ', flags->numb - l, flags->fd);
		counter += ft_pf_putnstr(ft_tr_nul(str, "(null)", str), l, flags->fd);
	}
	else if (flags->zero)
	{
		counter += ft_pf_putnchar('0', flags->numb - l, flags->fd);
		counter += ft_pf_putnstr(ft_tr_nul(str, "(null)", str), l, flags->fd);
	}
	else
		counter += ft_pf_putnstr(ft_tr_nul(str, "(null)", str), l, flags->fd);
	return (counter);
}
