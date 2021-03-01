/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 23:23:37 by hfadyl            #+#    #+#             */
/*   Updated: 2020/01/20 19:54:18 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_help_p(t_flag *flags, unsigned long long d, int l, char c)
{
	int	total;

	total = 0;
	c = (flags->precision == 0 ? ' ' : ' ');
	if (d == 0 && flags->precision == 0 && flags->option != '-')
	{
		total += print_spaces(' ', 2, flags->width);
		total += ft_putstr("0x");
	}
	else if (flags->option == '-' && d == 0 && flags->precision == 0)
	{
		total += ft_putstr("0x");
		total += print_spaces(' ', 2, flags->width);
	}
	else if (flags->option == '-')
	{
		total += ft_putstr(ft_simple_p(d));
		total += print_spaces(' ', l, flags->width);
	}
	else
	{
		total += print_spaces(c, l, flags->width);
		total += ft_putstr(ft_simple_p(d));
	}
	return (total);
}

static int	ft_help1_p(t_flag *flags, unsigned long long d, int l, char c)
{
	int total;

	total = 0;
	if (flags->option != '-')
	{
		if (d > 0)
		{
			total += print_spaces(c, flags->precision, flags->width);
			total += print_spaces('0', l, flags->precision);
			total += ft_putstr(ft_simple_p(d));
		}
		else if (d == 0)
		{
			total += print_spaces(c, flags->precision, flags->width);
			total += print_spaces('0', l, flags->precision);
			total += ft_putstr(ft_simple_p(d));
		}
		else if (flags->option == '-')
		{
			total += print_spaces('0', l, flags->precision);
			total += ft_putstr(ft_simple_p(d));
			total += print_spaces(c, flags->precision, flags->width);
		}
	}
	return (total);
}

static int	ft_help2_p(t_flag *flags, unsigned long long d, int l, char c)
{
	int total;

	total = 0;
	if (flags->width == 0 && flags->precision <= 0)
	{
		if (d == 0 && flags->precision == 0)
			total += ft_putstr("0x");
		else
			total += ft_putstr(ft_simple_p(d));
	}
	else if (flags->width > 0 && flags->precision <= 0)
		total += ft_help_p(flags, d, l, c);
	else if (flags->precision > 0 && flags->precision >= flags->width)
	{
		total += print_spaces('0', l, flags->precision);
		total += ft_putstr(ft_simple_p(d));
	}
	return (total);
}

static int	ft_help3_p(t_flag *flags, unsigned long long d, int l)
{
	int total;

	total = 0;
	if (flags->precision <= l)
	{
		if (flags->option == '-')
		{
			total += ft_putstr(ft_simple_p(d));
			total += print_spaces(' ', l, flags->width);
		}
		else
		{
			total += print_spaces(' ', l, flags->width);
			total += ft_putstr(ft_simple_p(d));
		}
	}
	else
		total += ft_help1_p(flags, d, l, ' ');
	return (total);
}

int			ft_treat_p(va_list arg, t_flag *flags)
{
	unsigned long long		d;
	int						l;
	int						total;
	char					c;

	c = (flags->option == '0' ? '0' : ' ');
	total = 0;
	d = va_arg(arg, unsigned long long);
	l = ft_strlen(ft_simple_p(d));
	total += ft_help2_p(flags, d, l, c);
	if (flags->precision > 0 && flags->width > 0)
		total += ft_help3_p(flags, d, l);
	return (total);
}
