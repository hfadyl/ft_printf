/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:48:31 by hfadyl            #+#    #+#             */
/*   Updated: 2020/01/20 20:29:52 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		g_d;
int		g_l;
int		g_total;
char	g_c;

static void	ft_help_d(t_flag *flags)
{
	if (flags->precision == 0)
		g_c = ' ';
	if (g_d == 0 && flags->precision == 0)
		g_total += print_spaces(' ', 0, flags->width);
	else if (flags->option == '-')
	{
		g_total += ft_putstr(ft_itoa(g_d));
		g_total += print_spaces(' ', g_l, flags->width);
	}
	else
	{
		if (g_d < 0 && g_c == '0')
		{
			g_d *= -1;
			g_total += ft_putchar('-');
		}
		g_total += print_spaces(g_c, g_l, flags->width);
		g_total += ft_putstr(ft_itoa(g_d));
	}
}

static void	ft_help1_d(t_flag *flags)
{
	if (g_d < 0)
	{
		g_d *= -1;
		g_total += ft_putchar('-');
		flags->precision += 1;
	}
	g_total += print_spaces('0', g_l, flags->precision);
	g_total += ft_putstr(ft_itoa(g_d));
}

static void	ft_help2_d(t_flag *flags)
{
	if (flags->precision == g_l)
		g_c = ' ';
	if (flags->option == '-')
	{
		g_total += ft_putstr(ft_itoa(g_d));
		g_total += print_spaces(' ', g_l, flags->width);
	}
	else
	{
		g_total += print_spaces(g_c, g_l, flags->width);
		g_total += ft_putstr(ft_itoa(g_d));
	}
}

static void	ft_help3_d(t_flag *flags)
{
	g_c = ' ';
	if (flags->option != '-')
	{
		if (g_d < 0)
			g_total += print_spaces(g_c, flags->precision + 1,
			flags->width);
		else
			g_total += print_spaces(g_c, flags->precision, flags->width);
		if (g_d < 0)
		{
			g_d *= -1;
			g_total += ft_putchar('-');
			flags->precision += 1;
		}
		g_total += print_spaces('0', g_l, flags->precision);
		g_total += ft_putstr(ft_itoa(g_d));
	}
	else if (flags->option == '-')
		g_total += ft_help4_d(flags, g_d, g_l, g_c);
}

int			ft_treat_d(va_list arg, t_flag *flags)
{
	g_c = (flags->option == '0' ? '0' : ' ');
	g_total = 0;
	g_d = va_arg(arg, int);
	g_l = int_len(g_d);
	if (flags->width == 0 && flags->precision == 0)
	{
		if (g_d == 0)
			return (g_total);
		else
			g_total += ft_putstr(ft_itoa(g_d));
	}
	else if (g_l > flags->precision && g_l > flags->width)
		g_total += ft_putstr(ft_itoa(g_d));
	else if (flags->width > 0 && flags->precision <= 0)
		ft_help_d(flags);
	else if (flags->precision > 0 && flags->precision >= flags->width)
		ft_help1_d(flags);
	else if (flags->precision > 0 && flags->width > 0)
	{
		if (flags->precision <= g_l)
			ft_help2_d(flags);
		else
			ft_help3_d(flags);
	}
	return (g_total);
}
