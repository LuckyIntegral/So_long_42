/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_vap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:42:41 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/19 22:03:23 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_nbrlen_ptr(unsigned long int n)
{
	size_t	res;

	if (!n)
		return (1);
	res = 0;
	while (n)
	{
		n = n / 16;
		res++;
	}
	return (res);
}

int	ft_pf_poff(size_t len, int zero, int dot)
{
	int	res;

	res = 0;
	if (dot)
		res = dot - len;
	else
		res = zero - 2 - len;
	if (res <= 0)
		return (0);
	return (res);
}

char	*ft_pf_ptox(unsigned long int nbr, int offset)
{
	size_t	len;
	char	*res;

	if (!nbr)
		return (ft_strdup("(nil)"));
	len = ft_pf_nbrlen_ptr(nbr) + 2 + offset;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res)
	{
		res[len] = '\0';
		while (len--)
		{
			res[len] = "0123456789abcdef"[nbr % 16ul];
			nbr = nbr / 16;
		}
		while (len-- && offset--)
			res[len] = '0';
		res[1] = 'x';
		res[0] = '0';
	}
	return (res);
}

int	ft_pf_vap(t_flags *flags, void *n)
{
	unsigned long int	value;
	char				*hex;
	int					counter;
	int					spaces;
	int					offset;

	counter = 0;
	value = (unsigned long int)n;
	offset = ft_pf_poff(ft_pf_nbrlen_ptr(value), flags->zero, flags->dot);
	hex = ft_pf_ptox(value, offset);
	if (hex)
	{
		spaces = ft_pf_get_spaces(flags, ft_strlen(hex));
		if (spaces > 0)
			counter += ft_pf_putnchar(' ', spaces, flags->fd);
		counter += write(flags->fd, hex, ft_strlen(hex));
		if (spaces < 0)
			counter += ft_pf_putnchar(' ', ft_abs(spaces), flags->fd);
	}
	free(hex);
	return (counter);
}
