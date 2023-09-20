/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_vax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 09:36:10 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/19 22:00:47 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_nbrlen_hex(int n)
{
	size_t	res;

	if (!n)
		return (1);
	if (n < 0)
		return (8);
	res = 0;
	while (n)
	{
		n = n / 16;
		res++;
	}
	return (res);
}

char	*ft_pf_itoa_hex(int n)
{
	unsigned long	nbr;
	char			*res;
	int				len;

	len = ft_pf_nbrlen_hex(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res)
	{
		res[len] = '\0';
		nbr = (unsigned long)ft_tr((n < 0), 4294967296l - ft_abs(n), n);
		while (len--)
		{
			res[len] = "0123456789abcdef"[nbr % 16];
			nbr = nbr / 16;
		}
	}
	return (res);
}

int	ft_pf_xoff(int strlen, int zero, int dot)
{
	int	res;

	res = 0;
	if (dot)
		res = dot - strlen;
	else
		res = zero - strlen;
	if (res <= 0)
		return (0);
	return (res);
}

int	ft_pf_vax(t_flags *flags, int nbr)
{
	char	*hex;
	int		counter;
	int		spaces;
	int		offset;

	counter = 0;
	hex = ft_pf_itoa_hex(nbr);
	if (hex)
	{
		offset = ft_pf_xoff(ft_strlen(hex), flags->zero, flags->dot);
		spaces = ft_pf_get_spaces(flags, ft_strlen(hex) + offset);
		if (spaces > 0)
			counter += ft_pf_putnchar(' ', spaces, flags->fd);
		counter += ft_pf_putnchar('0', offset, flags->fd);
		counter += write(flags->fd, hex, ft_strlen(hex));
		if (spaces < 0)
			counter += ft_pf_putnchar(' ', ft_abs(spaces), flags->fd);
		free(hex);
	}
	return (counter);
}
