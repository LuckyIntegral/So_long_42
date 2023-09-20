/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_vaid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:50:00 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/19 22:02:45 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_nbrlen(int n)
{
	size_t	i;

	i = 0ul;
	if (n <= 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_pf_itoa_offset(int nbr, int offset)
{
	size_t	len;
	char	*str;

	len = ft_pf_nbrlen(nbr) + offset;
	str = (char *)malloc(sizeof(char) * (++len));
	if (!str)
		return (str);
	str[--len] = '\0';
	if (!nbr)
		str[--len] = '0';
	while (nbr)
	{
		str[--len] = ft_abs(nbr % 10) + '0';
		nbr = nbr / 10;
	}
	while (offset--)
		str[--len] = '0';
	if (len)
		str[--len] = '-';
	return (str);
}

int	ft_pf_get_offset(int n, int zeros, int dots)
{
	int	res;

	if (dots)
	{
		if (dots == -1)
			return (1 - ft_pf_nbrlen(n));
		res = ft_tr(n >= 0, dots - ft_pf_nbrlen(n), dots - ft_pf_nbrlen(n) + 1);
	}
	else
		res = zeros - ft_pf_nbrlen(n);
	if (res < 0)
		return (0);
	return (res);
}

int	ft_pf_get_spaces(t_flags *flags, size_t strlen)
{
	int	res;

	res = 0;
	if (flags->minus)
		res = ft_max(flags->minus - strlen, 0) * -1;
	else if (flags->numb)
	{
		if (flags->numb < 0)
		{
			if (flags->dot)
				res = (flags->numb + strlen);
			else
				res = flags->numb + strlen;
		}
		else if (flags->numb >= (int)strlen)
			res = flags->numb - strlen;
	}
	else if (flags->zero && flags->dot)
		res = flags->zero - strlen;
	return (res);
}

int	ft_pf_vaid(t_flags *flags, int n)
{
	char	*res;
	int		counter;
	int		spaces;

	counter = 0;
	res = ft_pf_itoa_offset(n, ft_pf_get_offset(n, flags->zero, flags->dot));
	spaces = ft_pf_get_spaces(flags, ft_strlen(res));
	if (res)
	{
		if (spaces < 0)
		{
			counter += write(flags->fd, res, ft_strlen(res));
			counter += ft_pf_putnchar(' ', ft_abs(spaces), flags->fd);
		}
		else
		{
			counter += ft_pf_putnchar(' ', spaces, flags->fd);
			counter += write(flags->fd, res, ft_strlen(res));
		}
	}
	free(res);
	return (counter);
}
