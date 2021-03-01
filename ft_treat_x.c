/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 11:48:52 by hfadyl            #+#    #+#             */
/*   Updated: 2020/01/20 20:09:29 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int		g_d;
int					g_l;
int					g_total;
char				g_c;

static void	ft_help_x(t_flag *flags, short maj)
{
	if (flags->precision == 0)
		g_c = ' ';
	if (g_d == 0 && flags->precision == 0)
		g_total += print_spaces(' ', 0, flags->width);
	else if (flags->option == '-')
	{
		g_total += ft_putstr(ft_convhexa(g_d, maj));
		g_total += print_spaces(' ', g_l, flags->width);
	}
	else
	{
		g_total += print_spaces(g_c, g_l, flags->width);
		g_total += ft_putstr(ft_convhexa(g_d, maj));
	}
}

static void	ft_help1_x(t_flag *flags, short maj)
{
	if (g_d > 0)
	{
		g_total += print_spaces('0', g_l, flags->precision);
		g_total += ft_putstr(ft_convhexa(g_d, maj));
	}
	else
	{
		g_total += print_spaces('0', g_l, flags->precision);
		g_total += ft_putstr(ft_convhexa(g_d, maj));
	}
}

static void	ft_help2_x(t_flag *flags, short maj)
{
	if (flags->option == '-')
	{
		g_total += ft_putstr(ft_convhexa(g_d, maj));
		g_total += print_spaces(' ', g_l, flags->width);
	}
	else
	{
		g_total += print_spaces(' ', g_l, flags->width);
		g_total += ft_putstr(ft_convhexa(g_d, maj));
	}
}

static void	ft_help3_x(t_flag *flags, short maj)
{
	g_c = ' ';
	if (flags->option != '-')
	{
		if (g_d > 0)
		{
			g_total += print_spaces(g_c, flags->precision, flags->width);
			g_total += print_spaces('0', g_l, flags->precision);
			g_total += ft_putstr(ft_convhexa(g_d, maj));
		}
		else if (g_d == 0)
		{
			g_total += print_spaces(g_c, flags->precision, flags->width);
			g_total += print_spaces('0', g_l, flags->precision);
			g_total += ft_putstr(ft_convhexa(g_d, maj));
		}
	}
	else if (flags->option == '-')
	{
		g_total += print_spaces('0', g_l, flags->precision);
		g_total += ft_putstr(ft_convhexa(g_d, maj));
		g_total += print_spaces(g_c, flags->precision, flags->width);
	}
}

int			ft_treat_x(va_list arg, t_flag *flags, short maj)
{
	g_c = (flags->option == '0' ? '0' : ' ');
	g_total = 0;
	g_d = va_arg(arg, unsigned int);
	g_l = ft_strlen(ft_convhexa(g_d, maj));
	if (flags->width == 0 && flags->precision == 0)
	{
		if (g_d == 0)
			return (g_total);
		else
			g_total += ft_putstr(ft_convhexa(g_d, maj));
	}
	else if (g_l > flags->precision && g_l > flags->width)
		g_total += ft_putstr(ft_convhexa(g_d, maj));
	else if (flags->width > 0 && flags->precision <= 0)
		ft_help_x(flags, maj);
	else if (flags->precision > 0 && flags->precision >= flags->width)
		ft_help1_x(flags, maj);
	else if (flags->precision > 0 && flags->width > 0)
	{
		if (flags->precision <= g_l)
			ft_help2_x(flags, maj);
		else
			ft_help3_x(flags, maj);
	}
	return (g_total);
}
