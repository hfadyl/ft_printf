/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 09:42:12 by hfadyl            #+#    #+#             */
/*   Updated: 2020/01/20 20:46:27 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_checkprcs(va_list arg, t_flag *flags, char **format)
{
	*format = *format + 1;
	if (**format == '*')
	{
		flags->precision = va_arg(arg, int);
		if (flags->precision < 0)
			flags->precision = -1;
		*format = *format + 1;
	}
	else if (ft_isdigit(**format))
	{
		flags->precision = ft_atoi(*format);
		if (ft_isdigit(*(*format)))
			*format += int_len(flags->precision);
	}
	else
		flags->precision = 0;
}

static int	ft_checkoption(va_list arg, t_flag *flags, char **format)
{
	if (**format == '-')
	{
		flags->option = '-';
		return (1);
	}
	else if (**format == '0')
	{
		flags->option = '0';
		return (1);
	}
	else if (**format == '*')
	{
		flags->width = va_arg(arg, int);
		if (flags->width < 0)
		{
			flags->width *= -1;
			flags->option = '-';
		}
		return (1);
	}
	return (0);
}

int			ft_check_flag(char *format, va_list arg, t_flag *flags)
{
	ft_ini_flags(flags);
	while (!(ft_isalpha(*format)))
	{
		if (ft_checkoption(arg, flags, &format))
			format++;
		else if (ft_isdigit(*format))
		{
			flags->width = ft_atoi(format);
			if (ft_isdigit(*(format)))
				format += int_len(flags->width);
		}
		else if (*format == '.')
			ft_checkprcs(arg, flags, &format);
		else
			break ;
	}
	if ((ft_strchr("cspduixX%", *format)))
		flags->conversion = *format;
	return (0);
}

int			print_spaces(char c, int len, int w)
{
	int total;
	int x;

	total = 0;
	x = w - len;
	if (len < w)
	{
		while (x--)
			total += ft_putchar(c);
	}
	return (total);
}
