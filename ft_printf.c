/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:30:34 by hfadyl            #+#    #+#             */
/*   Updated: 2020/01/20 21:07:55 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_conv(char *format, va_list arg)
{
	if (*format == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (*format == 's')
		return (ft_putstr(va_arg(arg, char*)));
	else if (*format == 'p')
		return (print_str(ft_simple_p(va_arg(arg, unsigned long long))));
	else if (*format == 'd' || *format == 'i')
		return (print_str(ft_itoa(va_arg(arg, int))));
	else if (*format == 'u')
		return (print_str(ft_itoa_unsigned(va_arg(arg, unsigned int))));
	else if (*format == 'x')
		return (print_str(ft_convhexa(va_arg(arg, unsigned int), 0)));
	else if (*format == 'X')
		return (print_str(ft_convhexa(va_arg(arg, unsigned int), 1)));
	return (0);
}

static int	ft_secon_step(va_list arg, t_flag *flags)
{
	int total;

	total = 0;
	if (flags->conversion == 'd' || flags->conversion == 'i')
		total += ft_treat_d(arg, flags);
	else if (flags->conversion == 's')
		total += ft_treat_s(arg, flags);
	else if (flags->conversion == 'p')
		total += ft_treat_p(arg, flags);
	else if (flags->conversion == 'u')
		total += ft_treat_u(arg, flags);
	else if (flags->conversion == 'x' || flags->conversion == 'X')
		total += ft_treat_x(arg, flags, flags->conversion == 'X');
	else if (flags->conversion == 'c')
		total += ft_treat_c(arg, flags);
	else if (flags->conversion == '%')
		total += ft_treat_per(flags);
	return (total);
}

int			ft_first_step(char *format, va_list arg, t_flag *flags, int *step)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	if (ft_strchr("cspduixX", *format))
		total += ft_print_conv(format, arg);
	else
	{
		while (!(ft_strchr("cspduixX%", format[i])))
			i++;
		total += ft_check_flag(format, arg, flags);
		total += ft_secon_step(arg, flags);
	}
	*step = i + 1;
	return (total);
}

int			ft_princ(char *format, va_list arg, t_flag *flags)
{
	int step;
	int total;

	total = 0;
	while (*format != '\0')
	{
		step = 1;
		if (*format != '%')
		{
			total += ft_putchar(*format);
			format++;
		}
		else
		{
			format++;
			if (*format == '%')
				total += ft_putchar('%');
			else
				total += ft_first_step(format, arg, flags, &step);
			format += step;
		}
	}
	return (total);
}

int			ft_printf(char *format, ...)
{
	va_list		arg;
	t_flag		*flags;
	int			total;

	total = 0;
	if (!(flags = malloc(sizeof(t_flag))))
		return (0);
	va_start(arg, format);
	total += ft_princ(format, arg, flags);
	free(flags);
	va_end(arg);
	return (total);
}
