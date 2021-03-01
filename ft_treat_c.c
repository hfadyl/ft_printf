/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:30:46 by hfadyl            #+#    #+#             */
/*   Updated: 2020/01/20 21:09:35 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_help_c(int *total, int c, t_flag *flags)
{
	*total += print_spaces(' ', 0, flags->width - 1);
	*total += ft_putchar(c);
}

int			ft_treat_c(va_list arg, t_flag *flags)
{
	int total;
	int c;

	total = 0;
	c = va_arg(arg, int);
	if (flags->width == 0 && flags->precision >= 0)
		total += ft_putchar(c);
	else if (flags->precision <= 0 && flags->option == '-')
	{
		total += ft_putchar(c);
		total += print_spaces(' ', 0, flags->width - 1);
	}
	else if (flags->width >= 0 && flags->precision == -1)
	{
		total += print_spaces(' ', 0, flags->width - 1);
		total += ft_putchar(c);
	}
	else if (flags->width > 0 && flags->precision == 0)
		ft_help_c(&total, c, flags);
	else
		total = ft_putchar('\0');
	return (total);
}
