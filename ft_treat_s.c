/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 23:20:51 by hfadyl            #+#    #+#             */
/*   Updated: 2020/01/20 18:08:00 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_help_s(char **str, t_flag *flags, int *total, int *l)
{
	if (flags->option != '-')
	{
		*total += print_spaces(' ', *l, flags->width);
		*total += ft_putstr(*str);
	}
	else
	{
		*total += ft_putstr(*str);
		*total += print_spaces(' ', *l, flags->width);
	}
}

static void	ft_help3_s(t_flag *flags, int **l, char **str, int **total)
{
	if (flags->option == '-')
	{
		**total += ft_putstr(*str);
		**total += print_spaces(' ', **l, flags->width);
	}
	else
	{
		**total += print_spaces(' ', **l, flags->width);
		**total += ft_putstr(*str);
	}
}

static void	ft_help1_s(t_flag *flags, int *l, char **str, int *total)
{
	if (flags->precision < *l)
	{
		if (flags->option == '-')
		{
			*total += ft_putstr_len(*str, flags->precision);
			*total += print_spaces(' ', flags->precision, flags->width);
		}
		else
		{
			*total += print_spaces(' ', flags->precision, flags->width);
			*total += ft_putstr_len(*str, flags->precision);
		}
	}
	else
		ft_help3_s(flags, &l, str, &total);
}

static void	ft_help2_s(t_flag *flags, int *l, char **str, int *total)
{
	if (**str == '\0')
		*total += print_spaces(' ', 0, flags->width);
	else if (flags->precision < *l)
		*total += ft_putstr_len(*str, flags->precision);
	else
	{
		*total += print_spaces(' ', *l, flags->width);
		*total += ft_putstr(*str);
	}
}

int			ft_treat_s(va_list arg, t_flag *flags)
{
	int		total;
	char	*str;
	int		l;

	total = 0;
	str = va_arg(arg, char *);
	if (!str)
		str = ft_strdup("(null)");
	l = ft_strlen(str);
	if (flags->width > 0 && flags->precision == -1)
		ft_help_s(&str, flags, &total, &l);
	else if (flags->width >= 0 && flags->precision >= 0)
	{
		if (flags->width > flags->precision)
			ft_help1_s(flags, &l, &str, &total);
		else if (flags->width <= flags->precision)
			ft_help2_s(flags, &l, &str, &total);
	}
	else if (flags->precision == -1)
		total += ft_putstr(str);
	return (total);
}
