/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:34:43 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/19 22:08:11 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pf_parse_flag(t_flags *flags, const char *str, int i)
{
	int	temp;

	while (str[i] && ft_pf_isspec(str[i]))
	{
		if (ft_pf_istype(str[i]))
			break ;
		else if (str[i] == '*')
			flags->numb = (ft_pf_parse_number(str, &i));
		else if (str[i] == '0')
			flags->zero = ft_pf_parse_number(str, &i);
		else if (ft_isdigit(str[i]))
			flags->numb = ft_pf_parse_number(str, &i);
		else if (str[i] == '.')
		{
			temp = ft_pf_parse_number(str, &i);
			flags->dot = ft_tr(temp, temp, -1);
		}
		else if (str[i] == '-')
			flags->minus = ft_pf_parse_number(str, &i);
		else
			i++;
	}
	return (i);
}

int	ft_pf_put_arg(va_list *ap, t_flags *flags, char type)
{
	int	counter;

	counter = 0;
	if (type == '%')
		counter += ft_pf_vac(flags, '%');
	else if (type == 'c')
		counter += ft_pf_vac(flags, va_arg(*ap, int));
	else if (type == 's')
		counter += ft_pf_vas(flags, va_arg(*ap, char *));
	else if (type == 'p')
		counter += ft_pf_vap(flags, va_arg(*ap, void *));
	else if (type == 'd' || type == 'i')
		counter += ft_pf_vaid(flags, va_arg(*ap, int));
	else if (type == 'u')
		counter += ft_pf_vau(flags, va_arg(*ap, unsigned int));
	else if (type == 'x')
		counter += ft_pf_vax(flags, va_arg(*ap, int));
	else if (type == 'X')
		counter += ft_pf_vaxx(flags, va_arg(*ap, int));
	return (counter);
}

int	ft_pf_parse_args(va_list *ap, t_flags *flags, const char *str)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!str[i + 1])
				break ;
			ft_pf_flags_init(flags);
			i = ft_pf_parse_flag(flags, str, ++i);
			counter += ft_pf_put_arg(ap, flags, str[i++]);
		}
		else
			counter += ft_pf_putnchar(str[i++], 1, flags->fd);
	}
	return (counter);
}

int	ft_printf(const char *fmt, ...)
{
	t_flags	flags;
	va_list	ap;
	int		counter;

	flags.fd = STDOUT;
	if (!fmt || *fmt == '\0')
		return (0);
	va_start(ap, fmt);
	counter = ft_pf_parse_args(&ap, &flags, fmt);
	va_end(ap);
	return (counter);
}

int	ft_printf_fd(int fd, const char *fmt, ...)
{
	t_flags	flags;
	va_list	ap;
	int		counter;

	flags.fd = fd;
	if (!fmt || *fmt == '\0')
		return (0);
	va_start(ap, fmt);
	counter = ft_pf_parse_args(&ap, &flags, fmt);
	va_end(ap);
	return (counter);
}
