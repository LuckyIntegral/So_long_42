/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:02:48 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/19 22:07:42 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_parse_number(const char *str, int *i)
{
	size_t	res;

	if (str[*i] == '-' || str[*i] == '0' || str[*i] == '.')
		(*i)++;
	res = 0;
	while (ft_isdigit(str[*i]))
	{
		res = res * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (res);
}

void	ft_pf_flags_init(t_flags *flags)
{
	flags->dot = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->numb = 0;
}

int	ft_pf_istype(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_pf_isspec(char c)
{
	if (ft_isdigit(c) || c == '-' || c == '.' || ft_pf_istype(c))
		return (1);
	return (0);
}
