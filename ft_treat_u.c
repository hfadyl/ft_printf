/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:32:30 by hfadyl            #+#    #+#             */
/*   Updated: 2020/01/20 20:16:53 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int		g_d;
int					g_l;
int					g_total;
char				g_c;

static void	ft_help_u(t_flag *flags)
{
	if (flags->precision == 0)
		g_c = ' ';
	if (g_d == 0 && flags->precision == 0)
		g_total += print_spaces(' ', 0, flags->width);
	else if (flags->option == '-')
	{
		g_total += ft_putstr(ft_itoa_unsigned(g_d));
		g_total += print_spaces(' ', g_l, flags->width);
	}
	else
	{
		g_total += print_spaces(g_c, g_l, flags->width);
		g_total += ft_putstr(ft_itoa_unsigned(g_d));
	}
}

static void	ft_help1_u(t_flag *flags)
{
	if (g_d > 0)
	{
		g_total += print_spaces('0', g_l, flags->precision);
		g_total += ft_putstr(ft_itoa_unsigned(g_d));
	}
	else
	{
		g_total += print_spaces('0', g_l, flags->precision);
		g_total += ft_putstr(ft_itoa_unsigned(g_d));
	}
}

static void	ft_help2_u(t_flag *flags)
{
	if (flags->option == '-')
	{
		g_total += ft_putstr(ft_itoa_unsigned(g_d));
		g_total += print_spaces(' ', g_l, flags->width);
	}
	else
	{
		g_total += print_spaces(' ', g_l, flags->width);
		g_total += ft_putstr(ft_itoa_unsigned(g_d));
	}
}

static void	ft_help3_u(t_flag *flags)
{
	g_c = ' ';
	if (flags->option != '-')
	{
		if (g_d > 0)
		{
			g_total += print_spaces(g_c, flags->precision, flags->width);
			g_total += print_spaces('0', g_l, flags->precision);
			g_total += ft_putstr(ft_itoa_unsigned(g_d));
		}
		else if (g_d == 0)
		{
			g_total += print_spaces(g_c, flags->precision, flags->width);
			g_total += print_spaces('0', g_l, flags->precision);
			g_total += ft_putstr(ft_itoa_unsigned(g_d));
		}
	}
	else if (flags->option == '-')
	{
		g_total += print_spaces('0', g_l, flags->precision);
		g_total += ft_putstr(ft_itoa_unsigned(g_d));
		g_total += print_spaces(g_c, flags->precision, flags->width);
	}
}

int			ft_treat_u(va_list arg, t_flag *flags)
{
	g_c = (flags->option == '0' ? '0' : ' ');
	g_total = 0;
	g_d = va_arg(arg, unsigned int);
	g_l = uni_len(g_d);
	if (flags->width == 0 && flags->precision == 0)
	{
		if (g_d == 0)
			return (g_total);
		else
			g_total += ft_putstr(ft_itoa_unsigned(g_d));
	}
	else if (g_l > flags->precision && g_l > flags->width)
		g_total += ft_putstr(ft_itoa_unsigned(g_d));
	else if (flags->width > 0 && flags->precision <= 0)
		ft_help_u(flags);
	else if (flags->precision > 0 && flags->precision >= flags->width)
		ft_help1_u(flags);
	else if (flags->precision > 0 && flags->width > 0)
	{
		if (flags->precision <= g_l)
			ft_help2_u(flags);
		else
			ft_help3_u(flags);
	}
	return (g_total);
}
