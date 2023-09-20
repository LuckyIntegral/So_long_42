/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_vau.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 23:35:50 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/19 22:03:43 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_nbrulen(unsigned int n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_pf_itou_offset(unsigned int nbr, int offset)
{
	size_t	len;
	char	*str;

	len = ft_pf_nbrulen(nbr) + offset;
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
	return (str);
}

int	ft_pf_get_u_offset(unsigned int nbr, int zeros, int dots)
{
	int	res;

	if (dots)
		res = dots - ft_pf_nbrulen(nbr);
	else
		res = zeros - ft_pf_nbrulen(nbr);
	if (res < 0)
		return (0);
	return (res);
}

int	ft_pf_vau(t_flags *flags, unsigned int n)
{
	char	*res;
	int		counter;
	int		spaces;

	counter = 0;
	res = ft_pf_itou_offset(n, ft_pf_get_u_offset(n, flags->zero, flags->dot));
	if (res)
	{
		spaces = ft_pf_get_spaces(flags, ft_strlen(res));
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
		free(res);
	}
	return (counter);
}
