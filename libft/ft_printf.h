/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:16:20 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/19 22:07:56 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define STDOUT 1
# define HEX "0123456789abcdef"

typedef struct s_flags // for each field: 0 if nothing, else !0, ecxept fd
{
	int	minus;
	int	zero;
	int	dot;
	int	numb;
	int	fd;
}		t_flags;

// printf

int		ft_printf(const char *fmt, ...); // Works with stdout only
int		ft_printf_fd(int fd, const char *fmt, ...); // Works with custom fd

// type conversions

int		ft_pf_vap(t_flags *flags, void *n);
int		ft_pf_vau(t_flags *flags, unsigned int nbr);
int		ft_pf_vas(t_flags *flags, const char *str);
int		ft_pf_vac(t_flags *flags, const char c);
int		ft_pf_vaid(t_flags *flags, int nbr);
int		ft_pf_vaxx(t_flags *flags, int nbr);
int		ft_pf_vax(t_flags *flags, int nbr);

// function duplicates

size_t	ft_pf_parse_number(const char *str, int *i);
size_t	ft_pf_nbrlen_hex(int n);
size_t	ft_pf_nbrlen(int n);
void	ft_pf_flags_init(t_flags *flags);
char	*ft_pf_itoa_hex(int n);
int		ft_pf_get_spaces(t_flags *flags, size_t strlen);
int		ft_pf_xoff(int strlen, int zero, int dot);
int		ft_pf_putnstr(const char *str, int n, int fd);
int		ft_pf_putnchar(char c, int n, int fd);
int		ft_pf_istype(char c);
int		ft_pf_isspec(char c);

#endif
